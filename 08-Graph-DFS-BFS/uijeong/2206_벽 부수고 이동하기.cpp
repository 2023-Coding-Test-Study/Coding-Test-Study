#include <bits/stdc++.h>

using namespace std;

// 전역 변수로 두어야 메모리 초과 경고가 안뜬다. 
const int SIZE = 1000; // 배열 최대 크기
string arr[SIZE]; // 맵 
int d[SIZE][SIZE][2]; // 거리를 담을 맵 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; // 정수
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i]; // 맵 정보 받아오기 
	}

	queue<pair<pair<int, int>, int>> q; // BFS 구현을 위한 큐 
	q.push({ {0,0},1 }); // 시작점 넣기, 벽 부술 수 있음 
	d[0][0][1] = 1; // 이미 방문 
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int breaked = q.front().second;
		q.pop(); // 맨 앞 데이터 가져오기 

		if (x == N - 1 && y == M - 1) {
			cout << d[x][y][breaked]; // 종료점이면 
			return 0; // 종료 
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 미로 밖 범위일 경우 
			if (arr[nx][ny] == '1' && breaked) // 벽인데 부술 수 있는 경우 
			{
				q.push({ {nx,ny},0 }); // 큐에 추가 
				d[nx][ny][0] = d[x][y][1] + 1; // 거리 업데이트 
				
			}
			else if (arr[nx][ny] == '0' && !d[nx][ny][breaked]) {
				// 방문할 수 있는 노드이고 방문을 아직 안한 노드인 경우 
				q.push({ {nx,ny}, breaked }); 
				d[nx][ny][breaked] = d[x][y][breaked] + 1; // 거리 업데이트 
			}

		}
	}

	cout << "-1"; // 비정상적인 종료 
	return 0;

}
