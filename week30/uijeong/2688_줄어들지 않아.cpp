#include <bits/stdc++.h>

using namespace std;
long long dp[65][10];
int T, N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= 64; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = j; k <= 9; k++)
				dp[i][j] += dp[i - 1][k];

    cin >> T;
	while (T--) {
		cin >> N;
		long long ans = 0;
		for (int i = 0; i <= 9; i++)
			ans += dp[N][i];
		cout << ans << '\n';
	}

}
