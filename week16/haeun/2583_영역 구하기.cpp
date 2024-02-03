#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map> 
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

const int MAX = 101; 
int M, N, K; // M: 높이, N: 너비 
int graph[MAX][MAX];
bool visited[MAX][MAX]; 

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void paintRect(int x1, int y1, int x2, int y2) {
	for(int r = M - y2; r < M - y1; r++){
		for(int c = x1; c < x2; c++){
			if(graph[r][c] != 1) graph[r][c] = 1;
		}
	}
}

void dfs(int x, int y, vector<pii>& tmp){
	tmp.push_back({x, y});
	visited[x][y] = true;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		if(!visited[nx][ny] && graph[nx][ny] == 0){
			dfs(nx, ny, tmp);
		}
	}
}

void calcBlank() {
    // 분리된 각 영역의 크기 저장 
	vector<int> blanks; 

	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(!visited[i][j] && graph[i][j] == 0) {
				vector<pii> tmp;
				dfs(i, j, tmp);
				blanks.push_back(tmp.size());
			}
		}
	}

	cout << blanks.size() << "\n";

	sort(blanks.begin(), blanks.end());

	for(int e: blanks){
		cout << e << " ";
	}
}

void solution() {
	cin >> M >> N >> K;

	int x1, y1, x2, y2; 
	for(int i = 0; i < K; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		paintRect(x1, y1, x2, y2);
	}

	calcBlank();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solution();

	return 0; 
}
