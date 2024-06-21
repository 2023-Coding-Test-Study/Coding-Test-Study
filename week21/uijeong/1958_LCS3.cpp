#include<bits/stdc++.h>

using namespace std;

int A, B, C;
string a, b, c;
int dp[101][101][101]; // 모두 0으로 초기화 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	A = a.size();
	B = b.size();
	C = c.size();

	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= B; j++) {
			for (int k = 1; k <= C; k++) {
				if (a[i-1] == b[j-1] && a[i-1] == c[k-1]) {
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				}
				else {
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k-1]);
				}
			}
		}
	}

	cout << dp[A][B][C];
}
