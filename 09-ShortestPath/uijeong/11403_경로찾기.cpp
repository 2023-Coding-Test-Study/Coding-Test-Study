#include <bits/stdc++.h>
using namespace std;

int N;
int d[101][101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N; 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> d[i][j];
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d[i][k] + d[k][j] == 2) d[i][j] = 1; // 중간거점의 길이 존재한다
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
