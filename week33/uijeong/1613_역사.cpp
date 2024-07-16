#include <bits/stdc++.h>

using namespace std;

int N, K, s;
int d[405][405];
int def = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	fill(d[0], d[N + 1], def);
	for (int i = 0; i < K; i++) {
		int f, b;
		cin >> f >> b;
		d[f][b] = 1; 
	} // 간선 입력 및 업데이트 

	for (int i = 1; i <= N; i++) d[i][i] = 0; // 같은 위치
	for (int k = 1; k <= N; k++) { // 중간 정점
		for (int i = 1; i <= N; i++) { // 시작
			for (int j = 1; j <= N; j++) { // 도착
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
			}
		}
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		int f, b;
		cin >> f >> b;
		if (d[f][b] == def && d[b][f] == def) {
			cout << 0 << "\n";
		}
		else if (d[f][b] == def && d[b][f] != def) {
			cout << 1 << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
}
