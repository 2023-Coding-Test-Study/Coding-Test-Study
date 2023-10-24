#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring> 
#include <queue> 
using namespace std; 

const int MAX = 16; 
int columns[MAX]; // 열의 위치만 저장 
int N;
int ans = 0;

bool promising(int row) { 
	// 행은 서로 다른데 
	for(int i = 0; i < row; i++){ 
		// 같은 열에 있거나 
		if(columns[row] == columns[i] || 
			// 같은 대각선 상에 있는 경우 
			row - i == abs(columns[row] - columns[i])){
			return false; 
		}
	}
	return true; 
}

void nqueen(int row){
	// N개의 행까지 온 경우, 가능한 경우의 수 증가  
	if(row == N){
		ans++;
		return; 
	}

	for(int col = 0; col < N; col++){ 
		// (row, col)에 체스를 놓아본다. 
		columns[row] = col; 
		
		if(promising(row)){ 
			// 그 다음 행으로 넘어가기 
			nqueen(row + 1); 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; 

	nqueen(0); 

	cout << ans; 
	
	return 0;
}
