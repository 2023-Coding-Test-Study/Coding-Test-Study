#include <bits/stdc++.h>

using namespace std;

int N, k;
string vis[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. set input 
	cin >> N >> k;
	cin >> vis[0] >> vis[1];

	// 2. BFS
	queue<tuple<int, int, int>> q; // 시간, 번호 
	int dx[3] = { 1, -1, k};
	int dy[3] = 

	q.push(make_tuple(0, 0, 0)); // 방향, 시간, index
	
	int dir, time, pos;
	while (!q.empty()) {
		tie(dir, time, pos) = q.front(); q.pop();
		int dx[3] = { 1, -1, k };
		int dy[3] = { dir, dir, (dir + 1) % 2 }; // 현재 현재 반대

		for (int i = 0; i < 2; i++) {
			int nextPos = pos + dx[i];
			int nextDir = dy[i];

			if (nextPos <= time) continue; // 다음에 이동할 곳이 현재 시간보다 같거나 작으면 방문 x
			if (nextPos >= N) {
				cout << 1; // 성공
				return 0;
			}
			if (vis[nextDir][nextPos] == '0') continue; // 방문 못함

			q.push(make_tuple(nextDir, time+1, nextPos)); // 다음 좌표 이동 
		}
	}

	cout << 0;
	return 0;
}
