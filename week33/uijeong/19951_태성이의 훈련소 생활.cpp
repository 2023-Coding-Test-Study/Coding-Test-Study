#include <bits/stdc++.h>

using namespace std;

int N, M;
int h[1000002];
int sum[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> h[i];
	}

	for (int i = 1; i <= M; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		sum[a] += k;
		sum[b + 1] -= k;
	} // M번의 조교 명령 수행

	for (int i = 1; i < N; i++) {
		sum[i + 1] += sum[i];
	} //  누적합 수행

	for (int i = 1; i <= N; i++) {
		h[i] += sum[i];
		cout << h[i] << " ";
	}
}
