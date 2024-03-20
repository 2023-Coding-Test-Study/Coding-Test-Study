#include <bits/stdc++.h>
using namespace std;

int N = 0;
int A[1001];
vector<int> D(1001, 1); // 1로 초기화

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    D[1] = 1; // 초기값 정의
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                // 만약 i보다 작은 값이 존재한다면 
                D[i] = max(D[j] + 1, D[i]); 
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, D[i]);
    }
    cout << answer;
}
