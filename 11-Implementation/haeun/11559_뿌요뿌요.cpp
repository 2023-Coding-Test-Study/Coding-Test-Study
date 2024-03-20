#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

const int N = 12; 
const int M = 6; 

char board[N][M];
bool visited[N][M];
int answer = 0; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void input() {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j]; 
		}
	}
}

void dfs(int x, int y, vector<pii> &bomb){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위 체크 
		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		// 빈칸 체크 
		if(board[nx][ny] == '.') continue;

		// 방문 여부 체크 
		if(visited[nx][ny]) continue; 

		// 같은 색상인지 체크 
		if(board[x][y] != board[nx][ny]) continue;

		bomb.push_back({nx, ny});
		visited[nx][ny] = true;
		dfs(nx, ny, bomb);
	}
}

void downPuyo() {
	// N-2 행부터 위로 올라가면서 
	for(int i = N - 2; i >= 0; i--){
		for(int j = 0; j < M; j++){
			// 뿌요를 발견하면 
			if(board[i][j] != '.'){ 
				// 현재 행 번호 저장 
				int row = i; 

				// 마지막 행에 도달하거나 바로 밑의 행이 빈칸이 아닌 경우 종료
				while(true){
					if(row == N - 1 || board[row + 1][j] != '.') break; 
					row++;
				}

				// i번째 행에 있던 뿌요를 row번째 행으로 끌어내린다. 
				swap(board[row][j], board[i][j]); 
			}
		}
	}
}

void solution() {
	while(true){
		memset(visited, 0, sizeof(visited));
		bool stop = true; 

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				vector<pii> bomb; 

				// 방문하지 않은 뿌요를 발견하면 
				if(board[i][j] != '.' && !visited[i][j]){
					// 상하좌우를 탐색한다. 
					dfs(i, j, bomb); 
				}

				// 같은 색상의 뿌요가 4개 이상 인접해있는 경우 
				if(bomb.size() >= 4){ 
					stop = false; 

					// 해당하는 뿌요들을 터뜨린다. (빈칸으로 변경)
					for(auto pos: bomb){
						int x = pos.first; 
						int y = pos.second; 
						board[x][y] = '.';
					}
				}
			}
		}

		if(stop) break; 

		// 연쇄 횟수 갱신 
		answer++;

		// 빈칸을 메꾼다. 
		downPuyo(); 
	}

	cout << answer; 
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	solution();

	return 0; 
}
