#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int b[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < M; i++) cin >> b[i];

	int ida = 0;
	int idb = 0;
	
	while (ida < N || idb < M) {
		if (ida == N) { // a의 모든 원소를 확인했을 때
			cout << b[idb] << ' ';
			idb++;
		}
		else if (idb == M) { // b의 모든 원소를 확인했을 때
			cout << a[ida] << ' ';
			ida++;
		}
		else if (a[ida] >= b[idb]) { // 크기 비교
			cout << b[idb] << ' ';
			idb++;
		}
		else {
			cout << a[ida] << ' ';
			ida++;
		}
	}
}
