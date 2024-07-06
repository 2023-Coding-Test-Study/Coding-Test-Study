#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;
int graph[MAX][MAX];
int N, M; // 세로, 가로

// 우 상 좌 하 
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void input() {
	cin >> N >> M;

	for(int i = 0; i < N + 2; i++){
		for(int j = 0; j < M + 2; j++){
			if(i == 0 || i == N + 1) continue;
			if(j == 0 || j == M + 1) continue;
			cin >> graph[i][j];

			if(graph[i][j] == 1){
				graph[i][j] = -1; 
			}
		}
	}
}

void markHole() {
	// 0열
	for(int i = 1; i <= N; i++){
		graph[i][0] = i;
	}

	// N + 1행
	for(int i = 1; i <= M; i++){
		graph[N + 1][i] = N + i;
	}

	// M + 1열
	for(int i = N; i >= 1; i--){
		graph[i][M + 1] = (N + M) + (N - i + 1);
	}

	// 0행
	for(int i = M; i >= 1; i--){
		graph[0][i] = (2 * N + M) + (M - i + 1);
	}
}

int changeDirection(int dir){
	if(dir == 0) return 1; // 우 -> 상 
	else if(dir == 1) return 0; // 상 -> 우 
	else if(dir == 2) return 3; // 좌 -> 하 
	else return 2; // 하 -> 좌 
}

int dfs(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	
	if(graph[nx][ny] >= 1){
		return graph[nx][ny];
	}

	if(graph[nx][ny] == -1){
		return dfs(nx, ny, changeDirection(dir));
	}else{
		return dfs(nx, ny, dir);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	
	markHole();

	// 0열 
	for(int i = 1; i <= N; i++){
		cout << dfs(i, 0, 0) << " ";
	}

	// N+1행 
	for(int i = 1; i <= M; i++){
		cout << dfs(N + 1, i, 1) << " ";
	}

	// M+1열 
	for(int i = N; i >= 1; i--){
		cout << dfs(i, M + 1, 2) << " ";
	}

	// 0행 
	for(int i = M; i >= 1; i--){
		cout << dfs(0, i, 3) << " ";
	}
	
	return 0;
}