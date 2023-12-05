#include <bits/stdc++.h>
using namespace std;

int N, M;
int d[101][101] = { 0, };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1; // 비교한 값이 존재 
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d[i][k] + d[k][j] == 2) d[i][j] = 1; // 즉 k 무게를 통해 i와 j의 무게를 알 수 있음
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int count = 0;
        for (int j = 1; j <= N; j++) {
            if (d[i][j] == 0 && d[j][i] == 0) count++; // 둘 다 아무런 무게 관계가 없을 때 
        }
        cout << count-1 << "\n";
    }

    return 0;
}
