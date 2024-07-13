#include <bits/stdc++.h>

using namespace std;

int N, M; 
int board[1001][1001];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {0, 1, 0, -1};
int dir[4] = { 1, 0, 3, 2 }; // 왼 -> 위 위 -> 왼 오 -> 아래 아래 -> 오

int result(int x, int y) {
	// 결과값
	if (x <= 0) return 2 * N + 2 * M - y + 1;
	else if (x >= N + 1) return N + y;
	else if (y <= 0) return x;
	else if (y >= M + 1) return 2 * N + M - x + 1;
}

int search(int x, int y, int direction) {
	while (x >= 1 && x <= N && y >= 1 && y <= M) { // 하나라도 밖으로 벗어난 경우 아래로
		if (board[x][y] == 1) {
			direction = dir[direction]; // 방향 전환
		}

		x += dx[direction];
		y += dy[direction];
	}

	return result(x, y);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; i++) { // 왼쪽 
		cout << search(i, 1, 1) << " ";
	}
	for (int i = 1; i <= M; i++) { // 아래
		cout << search(N, i, 0) << " ";
	}
	for (int i = N; i >=1; i--) { // 오른쪽
		cout << search(i, M, 3) << " ";
	}
	for (int i = M; i >= 1; i--) { // 위
		cout << search(1, i, 2) << " ";
	}
}
