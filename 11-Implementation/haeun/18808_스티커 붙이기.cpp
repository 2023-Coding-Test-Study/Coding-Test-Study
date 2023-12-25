#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 41; 
int N, M, K; 
int R, C; 

int graph[MAX][MAX];
int sticker[MAX][MAX]; 
int temp[MAX][MAX];

bool isPossibleStick(int x, int y){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(graph[x + i][y + j] == 1 && sticker[i][j] == 1)
				return false; 
		}
	}
	
	return true; 
}

void putSticker(int x, int y){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(sticker[i][j] == 1) graph[x + i][y + j] = 1; 
		}
	}
}

void rotateSticker(){
	// 2차원 배열을 시계방향으로 90도 회전시킨다. 
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			temp[j][R - 1 - i] = sticker[i][j]; 
		}
	}

	// 행, 열의 크기 스왑 
	swap(R, C);

	// 배열의 값 복사
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			sticker[i][j] = temp[i][j];  
		}
	}
}

void solution() {
	for(int dir = 0; dir < 4; dir++){
		for(int i = 0; i + R <= N; i++){
			for(int j = 0; j + C <= M; j++){
				if(isPossibleStick(i, j)){
					putSticker(i, j);
					return; 
				}
			}
		}
		
		rotateSticker(); 
	}
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K; 

	while(K--){
		cin >> R >> C; 

		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin >> sticker[i][j]; 
			}
		}

		// i번째 스티커를 붙여본다. (안 되면 시계방향으로 90도 회전)
		solution(); 

		memset(sticker, 0, sizeof(sticker));
		memset(temp, 0, sizeof(temp));
	}

	int blank = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(graph[i][j] == 0) blank++;
		}
	}
	
	cout << N * M - blank; 

	return 0; 
}
