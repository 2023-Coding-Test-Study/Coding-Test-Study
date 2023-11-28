#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
using namespace std;
typedef pair<int, int> pii; 

const int MAX = 8; 
int N, M; 
int graph[MAX][MAX]; // 원본 지도 
int temp[MAX][MAX];  // 원본 지도의 복사본 

// 빈칸 중에서 3개의 벽 위치를 선택하기 위한 배열  
bool selected[MAX * MAX];

// 빈칸 위치 저장 
vector<pii> blanks; 

// 안전 영역 크기의 최댓값 
int ans = -1; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void input() {
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> graph[i][j]; 

			if(graph[i][j] == 0){
				blanks.push_back({i, j});
			}
		}
	}
}

// 원본 지도를 임시 배열에 복사한다. 
void copyMap() {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			temp[i][j] = graph[i][j]; 
		}
	}
}

// 선택된 3개의 위치에 벽을 세운다. 
void buildWalls() {
	int cnt = 0;
	for(int i = 0; i < blanks.size(); i++){
		if(cnt == 3) break; 
		if(selected[i]){
			int x = blanks[i].first; 
			int y = blanks[i].second; 
			temp[x][y] = 1; 
			cnt++; 
		}
	}
}

// 바이러스를 퍼뜨린다. 
void spreadViruses() {
	queue<pii> q; // 큐에 바이러스 위치 저장 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(temp[i][j] == 2){
				q.push({i, j}); 
			}
		}
	}

	while(!q.empty()){
		int x = q.front().first; 
		int y = q.front().second; 
		q.pop(); 

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; 

			if(temp[nx][ny] == 0){
				temp[nx][ny] = 2;
				q.push({nx, ny});
			}
		}
	}
}

// 남아있는 빈칸 개수를 세고 안전 영역의 최대 크기를 갱신한다. 
void updateSafeAreaMaxSize() {
	int cnt = 0; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(temp[i][j] == 0) cnt++; 
		}
	}
	ans = max(ans, cnt);
}

// 빈칸에 3개의 벽을 놓아보면서 안전 영역 크기의 최댓값 갱신 
void selectWallPosition(int idx, int cnt){
	if(cnt == 3){ 
		copyMap();
		buildWalls();
		spreadViruses(); 
		updateSafeAreaMaxSize(); 
		return; 
	} 

	for(int i = idx; i < blanks.size(); i++){
		if(!selected[i]){
			selected[i] = true; 
			selectWallPosition(cnt + 1, i + 1); 
			selected[i] = false; 
		}
	}
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	selectWallPosition(0, 0);

	cout << ans; 
}