#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX = 6;
int N, M; 
int arr[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0; 

// 우측 상단이 중심인 부메랑의 강도
int getRightTopPower(int r, int c) {
	return arr[r][c - 1] + arr[r + 1][c] + 2 * arr[r][c];
}

// 우측 하단이 중심인 부메랑의 강도
int getRightBottomPower(int r, int c) {
	return arr[r - 1][c] + arr[r][c - 1] + 2 * arr[r][c];
}

// 좌측 상단이 중심인 부메랑의 강도 
int getLeftTopPower(int r, int c) {
	return arr[r][c + 1] + arr[r + 1][c] + 2 * arr[r][c];
}

// 좌측 하단이 중심인 부메랑의 강도 
int getLeftBottomPower(int r, int c){
	return arr[r - 1][c] + arr[r][c + 1] + 2 * arr[r][c]; 
}

void dfs(int r, int c, int result){	
	if(c == M){
		c = 0; 
		r++;
	}

	if(r == N){
		ans = max(ans, result);
		return; 
	}

	if(!visited[r][c]){
		if(r + 1 < N && c - 1 >= 0 && !visited[r + 1][c] && !visited[r][c - 1]){
			visited[r][c] = true; 
			visited[r + 1][c] = true; 
			visited[r][c - 1] = true; 

			dfs(r, c + 1, result + getRightTopPower(r, c));

			visited[r][c] = false; 
			visited[r + 1][c] = false; 
			visited[r][c - 1] = false; 
		}

		if(r - 1 >= 0 && c - 1 >= 0 && !visited[r - 1][c] && !visited[r][c - 1]){
			visited[r][c] = true; 
			visited[r - 1][c] = true; 
			visited[r][c - 1] = true; 

			dfs(r, c + 1, result + getRightBottomPower(r, c));

			visited[r][c] = false; 
			visited[r - 1][c] = false; 
			visited[r][c - 1] = false; 
		}

		if(r + 1 < N && c + 1 < M && !visited[r + 1][c] && !visited[r][c + 1]){
			visited[r][c] = true; 
			visited[r + 1][c] = true; 
			visited[r][c + 1] = true; 

			dfs(r, c + 1, result + getLeftTopPower(r, c));

			visited[r][c] = false; 
			visited[r + 1][c] = false; 
			visited[r][c + 1] = false; 
		}

		if(r - 1 >= 0 && c + 1 < M && !visited[r - 1][c] && !visited[r][c + 1]){
			visited[r][c] = true; 
			visited[r - 1][c] = true; 
			visited[r][c + 1] = true; 

			dfs(r, c + 1, result + getLeftBottomPower(r, c));

			visited[r][c] = false; 
			visited[r - 1][c] = false; 
			visited[r][c + 1] = false; 
		}
	}

	dfs(r, c + 1, result); 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; 

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j]; 
		}
	}

	// 부메랑을 만들 수 없는 경우 예외 처리 
	if(N == 1 || M == 1){
		ans = 0; 
	}else{
		dfs(0, 0, 0);
	}

	cout << ans; 
	
	return 0;
}