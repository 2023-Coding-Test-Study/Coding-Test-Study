#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii; 

const int MAX = 8; 
const int WALL_NUM = 3; 
const int DIRECTION = 4; 

enum MapElement {
	BLANK, 
	WALL, 
	VIRUS
};

int N, M; 
int graph[MAX][MAX]; // 원본 지도 
int temp[MAX][MAX];  // 원본 지도의 복사본 

// 빈칸 중에서 3개의 벽 위치를 선택하기 위한 배열  
bool selected[MAX * MAX];

// BFS 방문 처리에 필요한 배열
bool visited[MAX][MAX];

// 빈칸, 바이러스 위치 저장 
vector<pii> blanks, viruses; 

// 안전 영역 크기의 최댓값 
int ans = -1;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void input() {
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> graph[i][j]; 

			if(graph[i][j] == BLANK){
				blanks.push_back({i, j});
			}

			if(graph[i][j] == VIRUS){
				viruses.push_back({i, j}); 
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
		if(cnt == WALL_NUM) break; 
		if(selected[i]){
			int x = blanks[i].first; 
			int y = blanks[i].second; 
			temp[x][y] = WALL; 
			cnt++; 
		}
	}
}

// 바이러스를 퍼뜨린다. 
void bfs(int a, int b) {
	queue<pii> q; 
	q.push({a, b});
	visited[a][b] = true; 

	while(!q.empty()){
		int x = q.front().first; 
		int y = q.front().second; 
		q.pop(); 

		for(int i = 0; i < DIRECTION; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; 

			if(temp[nx][ny] == BLANK && !visited[nx][ny]){
				temp[nx][ny] = VIRUS;
				q.push({nx, ny});
				visited[nx][ny] = true; 
			}
		}
	}
}

void dfs(int x, int y){
	visited[x][y] = true;

	for(int i = 0; i < DIRECTION; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; 

		if(temp[nx][ny] == BLANK && !visited[nx][ny]){
			temp[nx][ny] = VIRUS;
			dfs(nx, ny); 
		}
	}
}

// 방문 배열 초기화 하는 거 잊지 말기!! 
void initVisitedArray() {
	memset(visited, 0, sizeof(visited));
}

// 남아있는 빈칸 개수를 센다. 
int calcRemainBlank() {
	int cnt = 0; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(temp[i][j] == 0) cnt++; 
		}
	}
	return cnt; 
}

// 안전 영역의 최대 크기를 갱신한다. 
void updateSafeAreaMaxSize() {
	int cnt = calcRemainBlank(); 
	ans = max(ans, cnt); 
}

// 빈칸에 3개의 벽을 놓아보면서 안전 영역 크기의 최댓값 갱신 
void selectWallPosition(int idx, int cnt){
	if(cnt == WALL_NUM){
		copyMap();
		buildWalls();

		for(auto e: viruses){
			//bfs(e.first, e.second);
			dfs(e.first, e.second); 
		}

		initVisitedArray();
		updateSafeAreaMaxSize();
		return; 
	} 

	for(int i = idx; i < blanks.size(); i++){
		if(!selected[i]){
			selected[i] = true; 
			selectWallPosition(i + 1, cnt + 1); // 인자 순서 주의!! 
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
