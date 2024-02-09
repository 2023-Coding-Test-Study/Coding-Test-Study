#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

const int MAX = 101; 
int N; 

int graph[MAX][MAX];
bool sink[MAX][MAX];
bool visited[MAX][MAX]; 

int maxH = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void input(){
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> graph[i][j];
			maxH = max(graph[i][j], maxH);
		}
	}
}

void dfs(int x, int y){
	visited[x][y] = true;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i]; 
		int ny = y + dy[i];

		if(nx < 0 || nx >= N || ny < 0 | ny >= N) continue; 

		if(!visited[nx][ny] && !sink[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

void solution() {
	int curH = 0;
	int answer = 0;
	while(curH <= maxH) {
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				// curH 이하의 높이는 모두 잠긴다.
				if(graph[i][j] <= curH){
					sink[i][j] = true;
				}
			}
		}

		// 안전 영역의 크기 구하기
		int cnt = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(!visited[i][j] && !sink[i][j]){
					dfs(i, j);
					cnt++;
				}
			}
		}

		answer = max(cnt, answer);
		curH++;
		
		memset(visited, 0, sizeof(visited));
		memset(sink, 0, sizeof(sink));
	}

	cout << answer; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 

	return 0; 
}