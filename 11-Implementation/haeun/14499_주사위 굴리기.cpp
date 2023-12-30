#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 21;
int N, M, K, x, y;
int map[MAX][MAX];
vector<int> cmd; 

// 주사위 면: 위 북 동 서 남 아래 (초기에는 모든 면을 0으로 초기화)
vector<int> dice(7, 0); 

// 주사위 굴리는 방향: 동 서 북 남
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void input() {
	cin >> N >> M >> x >> y >> K; 

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 0; i < K; i++){
		int dir; 
		cin >> dir; 
		cmd.push_back(dir - 1);
	}
}

void rollEast(){
	dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
}

void rollWest(){
	dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

void rollNorth(){
	dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
}

void rollSouth(){
	dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}
void rollDice(int direction){
	switch(direction){
		case 0: rollEast(); break; 
		case 1: rollWest(); break; 
		case 2: rollNorth(); break; 
		case 3: rollSouth(); break; 
		default: break; 
	}
}

void solution() {
	for(auto dir: cmd){
		// 주사위의 다음 위치 계산 
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 범위 체크 
		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; 

		// 명령어에 따라 주사위 굴리기 
		rollDice(dir);

		if(map[nx][ny] == 0){
			// 바닥면에 적힌 숫자를 칸에 복사 
			map[nx][ny] = dice[6]; 
		}else{
			// 칸에 적힌 숫자를 주사위 바닥면에 복사 
			dice[6] = map[nx][ny];
			
			// 칸은 0으로 변경 
			map[nx][ny] = 0; 
		}

		// 주사위 윗면에 적힌 수 출력 
		cout << dice[1] << "\n";

		// 주사위 위치 갱신 
		x = nx; 
		y = ny; 
	}
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	solution();

	return 0; 
}
