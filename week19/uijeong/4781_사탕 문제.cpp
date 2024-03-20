#include <bits/stdc++.h>
using namespace std;

int N;
double M; 
pair<int, double> candy[5001]; 
int dp[5001][10001]; 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		// 하나의 test case
		cin >> N >> M;
		if (N == 0 && M == 0.00) break; 

		for (int i = 1; i <= N; i++) {
			cin >> candy[i].first >> candy[i].second;
		} 

		sort(candy, candy + N + 1); 
		int money = (int)(M * 100+0.5); // 즉 형변환 전에 0.5를 더해준다. 
		for (int i = 1; i <= N; i++) { 
			for (int j = 0; j <= money; j++) { 
				int c = int(candy[i].second * 100+0.5); // 즉 형변환 전에 0.5를 더해준다. 
				if (j < c) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = max(dp[i - 1][j], candy[i].first + dp[i][j - c]); 
			}
		}

		cout << dp[N][money] << "\n";
	}

	return 0;
}
