#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[301][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> d(N+1, vector<int>(K+1, 0)); // N행 K열 0으로 초기화 

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (A[i][1] > j) { // 만약 물건 i의 무게가 현재 넣을 무게 j를 넘는다면
                d[i][j] = d[i-1][j]; 
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - A[i][2]] + A[i][1]);
            }
        }
    }

    cout << d[N][K];
}
