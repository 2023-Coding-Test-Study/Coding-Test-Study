#include <bits/stdc++.h>
using namespace std;

int N, C;
int house[200001];

bool checkDistance(int s) {
    int count = 1; // 제일 첫번째에 설치 가능 
    long long prev = house[0];

    for (int i = 1; i < N; i++) {
        if (house[i] - prev >= s) {
            // 거리 이상인 경우 
            count++;
            prev = house[i];
        }
    }

    return count >= C; // 공유기 거리를 더 넓힐 수 있을 때
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }
    sort(house, house + N); // 오름차순

    long long st = 1;
    long long ed = house[N-1]-house[0];

    while (st < ed) {
        long long mid = (st + ed+1) / 2; 

        if (checkDistance(mid)) {
            st = mid; // 공유기 거리를 더 넓혀도 됨
        }
        else ed = mid - 1; // 더 줄여야 함 
    }

    cout << st;
}
