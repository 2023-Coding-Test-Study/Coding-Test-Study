#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 9;
int N, M;

int graph[MAX][MAX]; 
int temp[MAX][MAX]; 
vector<pair<pii, pii>> cctv;

int ans = 1e9;
int cctvCount = 0;

// 동서남북 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
	cin >> N >> M;

	// 0: 빈칸, 6: 벽, 1~5: CCTV
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> graph[i][j];
			
			if(graph[i][j] >= 1 && graph[i][j] <= 5){
				// {{x, y}, {번호, 방향}}
				cctv.push_back({{i, j}, {graph[i][j], -1}});
			}
		}
	}

	// cctv 총 개수 초기화 
	cctvCount = cctv.size();
}

void copyGraphArray() {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			temp[i][j] = graph[i][j]; 
		}
	}
}

void moveRight(int x, int y){
	for(int i = y + 1; i < M; i++){
		if(temp[x][i] == 6) break; 
		if(temp[x][i] >= 1 && temp[x][i] <= 5) continue; 
		temp[x][i] = -1; 
	}
}

void moveLeft(int x, int y){
	for(int i = y - 1; i >= 0; i--){
		if(temp[x][i] == 6) break; 
		if(temp[x][i] >= 1 && temp[x][i] <= 5) continue; 
		temp[x][i] = -1; 
	}
}

void moveBottom(int x, int y){
	for(int i = x + 1; i < N; i++){
		if(temp[i][y] == 6) break; 
		if(temp[i][y] >= 1 && temp[i][y] <= 5) continue; 
		temp[i][y] = -1; 
	}
}

void moveTop(int x, int y){
	for(int i = x - 1; i >= 0; i--){
		if(temp[i][y] == 6) break; 
		if(temp[i][y] >= 1 && temp[i][y] <= 5) continue; 
		temp[i][y] = -1; 
	}
}

void checkVisibleArea() {
	copyGraphArray(); 

	for(int i = 0; i < cctv.size(); i++){
		int x = cctv[i].first.first;
		int y = cctv[i].first.second; 
		int num = cctv[i].second.first;
		int dir = cctv[i].second.second; 

		// 동서남북 중에 한 방향 
		if(num == 1){
			if(dir == 0){
				moveRight(x, y);
			}else if(dir == 1){
				moveLeft(x, y);
			}else if(dir == 2){
				moveBottom(x, y);
			}else if(dir == 3){
				moveTop(x, y);
			}
		}
		// 동서 또는 남북 중에 한 방향 
		else if(num == 2){
			if(dir == 0 || dir == 1){
				moveRight(x, y);
				moveLeft(x, y);
			}else if(dir == 2 || dir == 3){
				moveBottom(x, y);
				moveTop(x, y);
			}
		}
		// 90도 방향 
		else if(num == 3){
			if(dir == 0){
				moveRight(x, y);
				moveTop(x, y);
			}else if(dir == 1){
				moveLeft(x, y);
				moveBottom(x, y);
			}else if(dir == 2){
				moveRight(x, y);
				moveBottom(x, y);
			}else if(dir == 3){
				moveLeft(x, y);
				moveTop(x, y);
			}
		}
		// 세 방향
		else if(num == 4){
			if(dir == 0){
				moveRight(x, y);
				moveTop(x, y);
				moveBottom(x, y);
			}else if(dir == 1){
				moveLeft(x, y);
				moveTop(x, y);
				moveBottom(x, y);
			}else if(dir == 2){
				moveRight(x, y);
				moveLeft(x, y);
				moveBottom(x, y);
			}else if(dir == 3){
				moveRight(x, y);
				moveLeft(x, y);
				moveTop(x, y);
			}
		}
		// 동서남북 모든 방향 
		else if(num == 5){
			moveRight(x, y);
			moveLeft(x, y);
			moveBottom(x, y);
			moveTop(x, y);
		}
	}
}

int getUnvisibleAreaSize() {
	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(temp[i][j] == 0) cnt++; 
		}
	}
	return cnt;
}

void setDirection(int idx) {
	if(idx == cctvCount){
		checkVisibleArea(); 
		ans = min(ans, getUnvisibleAreaSize());
		return;
	}

	cctv[idx].second.second = 0; 
	setDirection(idx + 1);

	cctv[idx].second.second = 1; 
	setDirection(idx + 1);

	cctv[idx].second.second = 2; 
	setDirection(idx + 1);

	cctv[idx].second.second = 3; 
	setDirection(idx + 1);
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
