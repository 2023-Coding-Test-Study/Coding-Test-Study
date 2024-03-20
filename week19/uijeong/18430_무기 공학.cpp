#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[6][6]; // 입력값 
bool vis[6][6]; // 방문 확인 
vector<pair<int, int>> d[4] = { {{-1, 0 }, {0, 1}}, {{-1,0}, {0, -1}}, {{0, -1}, {1, 0}}, {{0, 1}, {1,0}} };
int ans = 0;

void booSum(int x, int y, int sum) { // 각각 x좌표, y좌표, 현재 합
	ans = max(ans, sum);

	// 다음 줄로 넘어가야 할 때 
	if (y == M) {
		y = 0;
		x++;
	}
	// 종료 조건
	if (x == N) return; // x == N이고 y == M인 경우 

	if (!vis[x][y]) { // 해당 중심값을 방문 가능할 때 
		for (int k = 0; k < 4; k++) {
			// 4가지 부메랑 모양 
			int nx1 = x + d[k][0].first;
			int ny1 = y + d[k][0].second;
			int nx2 = x + d[k][1].first;
			int ny2 = y + d[k][1].second;

			if (nx1 >= 0 && nx2 >= 0 && nx1 < N && nx2 < N && ny1 >= 0 && ny2 >= 0 && ny1 < M && ny2 < M) {
				if (vis[nx1][ny1] || vis[nx2][ny2]) continue;
				vis[nx1][ny1] = 1;
				vis[nx2][ny2] = 1;
				vis[x][y] = 1;

				booSum(x, y + 1, sum + (board[x][y] * 2) + board[nx1][ny1] + board[nx2][ny2]);

				vis[x][y] = 0;
				vis[nx1][ny1] = 0;
				vis[nx2][ny2] = 0;
			}
		}
	}
	booSum(x, y + 1, sum); // 부메랑 못 만듬.. 그냥 넘어가! 

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	} // 입력 처리 

	booSum(0, 0, 0);
	cout << ans;

}
