#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp = 0; 
        cin >> temp;
        a.push_back(temp);
    }
    cin >> S;

    for (int i = 0; i < N; i++) {
        int max = a[i]; // 초기 숫자
        int maxi = i; // 인덱스 저장

        for (int j = i + 1; j < N; j++) // i를 제외한 나머지 수들 중
        {
            if (S - (j - i) >= 0) // 교환 횟수가 S보다 작을 것 같다면
            {
                if (max < a[j]) // 해당 숫자가 max보다 클때 
                {
                    max = a[j]; // max는 이 친구로 변동 - target
                    maxi = j;
                }
            }
        }

        for (int j = maxi; j > i; j--) // max값을 정한 후 연속된 원소들끼리 자리 바꿈
            swap(a[j], a[j - 1]);
        S -= (maxi - i); // S 횟수 제거
        if (S <= 0) 
            break;

    }

    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
}
