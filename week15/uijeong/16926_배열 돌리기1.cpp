#include <bits/stdc++.h>
using namespace std;

int a[301][301];
int temp = 0;
int N, M, R;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    } // input 

    int d = min(N, M) / 2; // 순환해야 하는 깊이 

    while (R > 0) {
        for (int c = 0; c < d; c++) {
            temp = a[c+1][c+1];
            
            // 오 -> 왼
            for (int i = c+1; i <= M-1-c; i++) {
                a[c+1][i] = a[c+1][i+1];
            }
            // 아 -> 위 
            for (int i = c+1; i <= N-1-c; i++) {
                a[i][M-c] = a[i+1][M-c];
            }
            // 왼 -> 오
            for (int i = M-1-c; i >= 1+c; i--) {
                a[N-c][i+1] = a[N-c][i];
            }
            // 위 -> 아
            for (int i = N-1-c; i >= 2+c; i--) {
                a[i+1][c+1] = a[i][c+1];
            }
            // c,c 처리 
            a[c + 2][c+1] = temp;
        }
        R--;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    } // output
    
}
