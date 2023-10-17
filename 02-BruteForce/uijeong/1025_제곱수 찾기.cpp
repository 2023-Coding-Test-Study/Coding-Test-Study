#include <bits/stdc++.h>

using namespace std;

bool isSqure(int n) {
	int root = (int)sqrt(n);
	return root * root == n;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int arr[9][9];
	int ans = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	// 값 대입

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int x = -N; x < N; x++) { // 행의 등차
				for (int y = -M; y < M; y++) { // 열의 등차
					if (x == 0 && y == 0) continue; // 계속 제자리 이므로 넘긴다.
					int a = i;
					int b = j;
					int num = 0;

					while (a >= 0 && a < N && b >= 0 && b < M) {
						num *= 10; // 10진수 올리기 
						num += arr[a][b]; // 칸 수 늘린거라 생각하면 된다.
						if (isSqure(num)) ans = max(ans, num);
						a += x;
						b += y;
					}
				}
			}
		}
	}
	cout << ans;

}
