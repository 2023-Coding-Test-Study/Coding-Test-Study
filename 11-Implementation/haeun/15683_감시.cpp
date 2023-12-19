#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 8;
int N, M;

int graph[MAX][MAX];
vector<pii> cctv;

int ans = MAX * MAX;
int cctvCount = 0; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void input() {
	cin >> N >> M;

	// 0: 빈칸, 6: 벽, 1~5: CCTV 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> graph[i][j];

			// cctv에 관한 정보 저장 
			if(graph[i][j] >= 1 && graph[i][j] <= 5){
				cctv.push_back({i, j});
			}
		}
	}

	cctvCount = cctv.size();
}

void checkVisibleArea(int dir, int x, int y) {
	dir %= 4; // 0~3 중에 방향 설정하기

	while(true){
		// dir 방향으로 직진하다가 
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 벽을 마주치면 종료 
		if(nx < 0 || nx >= N || ny < 0 || ny >= M || 
			graph[nx][ny] == 6) break;

		// cctv로 감시 가능한 영역 표시하기 
		if(graph[nx][ny] == 0){
			graph[nx][ny] = -1;
		}

		// 다음 위치 갱신 
		x = nx; 
		y = ny; 
	}
}

void updateMinUnvisibleAreaSize() {
	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(graph[i][j] == 0) cnt++; 
		}
	}
	ans = min(ans, cnt);
}

void setDirection(int idx) {
	if(idx == cctvCount){
		updateMinUnvisibleAreaSize(); 
		return;
	}

	int x = cctv[idx].first;
	int y = cctv[idx].second;

	// 복사본 배열 초기화 
	int temp[N][M];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			temp[i][j] = graph[i][j]; 
		}
	}

	for(int dir = 0; dir < 4; dir++){
		// 변경된 그래프 상태 반영 
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				temp[i][j] = graph[i][j]; 
			}
		}
		
		// cctv 종류에 따라 감시 가능한 영역 표시 
		if(graph[x][y] == 1){ // 한 방향
			checkVisibleArea(dir, x, y);
		}
		else if(graph[x][y] == 2){ // 180도 방향 
			checkVisibleArea(dir, x, y);
			checkVisibleArea(dir + 2, x, y);
		}
		else if(graph[x][y] == 3){ // 90도 방향 
			checkVisibleArea(dir, x, y);
			checkVisibleArea(dir + 1, x, y);
		}
		else if(graph[x][y] == 4){ // 세 방향 
			checkVisibleArea(dir, x, y);
			checkVisibleArea(dir + 1, x, y);
			checkVisibleArea(dir + 2, x, y);
		}
		else if(graph[x][y] == 5){ // 네 방향 
			checkVisibleArea(dir, x, y);
			checkVisibleArea(dir + 1, x, y);
			checkVisibleArea(dir + 2, x, y);
			checkVisibleArea(dir + 3, x, y);
		}

		// 그 다음 cctv에 대한 방향 설정
		setDirection(idx + 1);

		// 모든 cctv에 대한 방향 설정이 끝나면 
		// 그 다음 경우의 수를 위해 원본 배열 복원하기 
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				graph[i][j] = temp[i][j]; 
			}
		}
	}
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	setDirection(0); 

	cout << ans; 

	return 0; 
}
