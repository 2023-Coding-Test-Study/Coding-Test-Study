#include <bits/stdc++.h>

using namespace std;

long long d[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;

    cin >> n >> k;
    
    d[1][0] = 1;
    d[1][1] = 1;
    if (n == 1) {
        cout << d[1][0];
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) d[i][j] = 1;
            else if (i == j) d[i][j] = 1;
            else {
                d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007; // 내가 추가한 부분..
            }
        }
    }

    cout << d[n][k];
}
