#include<bits/stdc++.h>

using namespace std;

int T, N;
string g, t;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int b_c = 0;
		int w_c = 0;

		cin >> N;
		cin >> g >> t;

		for (int j = 0; j < N; j++) {
			if (g[j] != t[j] && g[j] == 'B') b_c++;
			else if (g[j] != t[j] && g[j] == 'W') w_c++;
		}
		cout << max(b_c, w_c) << "\n";
	}
}
