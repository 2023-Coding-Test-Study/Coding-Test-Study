#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 101; 
int N, K, L;

int board[MAX][MAX];
vector<pair<int, char>> v;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

enum Board {
	BLANK, 
	APPLE, 
	SNAKE
};

void input() {
	cin >> N >> K;

	// 사과 위치 초기화
	for(int i = 0; i < K; i++){
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = APPLE;
	}

	// 뱀의 방향 전환 정보 
	cin >> L; 
	for(int i = 0; i < L; i++){
		int time; 
		char dir;
		cin >> time >> dir;
		v.push_back({time, dir});
	}
}

void solution() {
	deque<pii> dq; // 뱀의 머리와 꼬리 위치 저장 

	// 뱀의 초기 위치와 방향 
	int x = 0, y = 0; 
	int dir = 2; 

	// 덱과 보드판 초기화
	dq.push_back({x, y});
	board[x][y] = SNAKE;

	// 현재 시간 초기화 
	int time = 0; 
	int idx = 0; 

	// 게임 진행 
	while(true){
		time++; 

		// 현재 방향에 따라 다음 위치 구하기 
		int nx = x + dx[dir]; 
		int ny = y + dy[dir]; 

		// 보드판을 벗어나거나 뱀의 몸통과 겹치면 게임 종료 
		if(nx < 0 || nx >= N || ny < 0 || ny >= N) break; 
		if(board[nx][ny] == SNAKE) break; 

		// 빈 공간인 경우 (머리와 꼬리 모두 이동)
		if(board[nx][ny] == BLANK){
			board[nx][ny] = SNAKE; // 머리 이동
			
			auto tail = dq.back();
			board[tail.first][tail.second] = BLANK; // 꼬리 이동

			dq.pop_back(); // 꼬리 위치 제거 
			dq.push_front({nx, ny}); // 머리 위치 삽입 
		}
		// 사과가 있는 경우 (머리만 이동)
		else if(board[nx][ny] == APPLE) {
			// 머리 이동 
			board[nx][ny] = SNAKE;

			// 머리 위치 삽입
			dq.push_front({nx, ny});
		}

		// 뱀의 방향 갱신 
		if(idx < v.size()){
			if(time == v[idx].first) {
				if(v[idx].second == 'L'){
					dir = (dir + 3) % 4; 
				}else{
					dir = (dir + 1) % 4; 
				}
				idx++; 
			}
		}

		// 뱀의 위치 갱신
		x = nx; 
		y = ny; 
	}

	cout << time;
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	solution();

	return 0; 
}
