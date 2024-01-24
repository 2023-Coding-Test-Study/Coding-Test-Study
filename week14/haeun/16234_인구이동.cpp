#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

const int MAX = 51; 
int N, L, R;
int graph[MAX][MAX];
bool visited[MAX][MAX];
bool movable = true; // 이동 가능한지 체크 

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
	cin >> N >> L >> R;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> graph[i][j];
		}
	}
}

// 한 군데라도 이동 가능한 방향이 있다면 true 반환
bool possibleMove(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue; 

		int gap = abs(graph[x][y] - graph[nx][ny]);
		if(gap >= L && gap <= R) return true; 
	}
	
	return false;
}

void bfs(int a, int b){
	queue<pii> q, temp;
	q.push({a, b});
	temp.push({a, b}); // 방문한 국가의 위치 저장 (인구 수 갱신을 위해)
	visited[a][b] = true; 
	int sum = 0;
	int cnt = 0;
	
	while(!q.empty()){
		int x = q.front().first; 
		int y = q.front().second; 
		q.pop(); 

		sum += graph[x][y]; // 연합 국가의 인구 수 갱신 
		cnt++; // 연합 국가의 개수 갱신 

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue; 

			// 국경선을 넘어서 이동 가능한지 검사 
			int gap = abs(graph[x][y] - graph[nx][ny]);
			if(!visited[nx][ny] && gap >= L && gap <= R) {
				visited[nx][ny] = true; 
				q.push({nx, ny});
				temp.push({nx, ny});
			}
		}
	}

	int newVal = sum / cnt; 
	while(!temp.empty()){
		int x = temp.front().first; 
		int y = temp.front().second; 
		temp.pop(); 
		graph[x][y] = newVal; 
	}
}

void solution() {
	int day = 0; 

	while(movable) {
		movable = false;
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(!visited[i][j] && possibleMove(i, j)) {
					bfs(i, j);
					movable = true; 
				}
			}
		}

		if(movable) day++;
		memset(visited, false, sizeof(visited));
	}

	cout << day << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 
}
