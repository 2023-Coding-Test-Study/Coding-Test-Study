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

int N, k;
const int MAX = 100001;
int graph[2][MAX];
bool visited[2][MAX]; // 같은 칸은 재방문 하지 않도록
bool possible;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input(){
	cin >> N >> k;

	// 각 행의 숫자들이 공백 없이 입력되므로, 문자열 활용! 
	for(int i = 0; i < 2; i++){
		string input;
		cin >> input;
		
		for(int j = 0; j < N; j++){
			graph[i][j] = input[j] - '0';
		}
	}
}

void bfs(int x, int y, int startTime){
	queue<pair<pii, int>> q;
	q.push({{x, y}, startTime});
	visited[x][y] = true;

	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int row = cur.first.first;
		int col = cur.first.second;
		int time = cur.second;

		// N초가 되면 칸이 모두 사라짐.
		if(time >= N) break;
		
		for(int i = 0; i < 4; i++){
			int nx, ny;
			if(i == 0 || i == 1){ // 좌우 이동 
				nx = row + dx[i];
				ny = col + dy[i];
			}else{ // 상하 이동 
				nx = row + dx[i];
				ny = col + dy[i] + k; // 오른쪽으로 k칸 
			}

			if(ny >= N){
				possible = true;
				break;
			}

			// 시간이 지날수록 왼쪽 방향의 열로 이동 불가!! 
			if(nx < 0 || nx >= 2 || ny <= time || ny >= N) continue;
			
			if(!visited[nx][ny] && graph[nx][ny] == 1){
				q.push({{nx, ny}, time + 1});
				visited[nx][ny] = true;
			}
		}
	}
}

void solution(){
	bfs(0, 0, 0);
	cout << possible;
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
	
	return 0;
}
