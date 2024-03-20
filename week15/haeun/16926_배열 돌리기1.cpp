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

const int MAX = 301; 
int N, M, R; 
int arr[MAX][MAX]; 

void input() {
	cin >> N >> M >> R; 

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
}

void rotateArray() {
	int depth = min(N, M) / 2; 
	
	for(int k = 0; k < depth; k++){
		int r = k, c = k;
		int prev = arr[r][c];

		// 아래로 이동 
		while(r < N - 1 - k) {
			int next = arr[r + 1][c]; 
			arr[r + 1][c] = prev; 
			prev = next; 
			r++; 
		}

		// 오른쪽으로 이동 
		while(c < M - 1 - k){
			int next = arr[r][c + 1];
			arr[r][c + 1] = prev; 
			prev = next; 
			c++; 
		}

		// 위쪽으로 이동 
		while(r >= k + 1){
			int next = arr[r - 1][c];
			arr[r - 1][c] = prev; 
			prev = next; 
			r--;
		}

		// 왼쪽으로 이동 
		while(c >= k + 1) {
			int next = arr[r][c - 1];
			arr[r][c - 1] = prev; 
			prev = next; 
			c--; 
		}
	}
}

void solution() {
	while(R--){
		rotateArray();
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << arr[i][j] << " "; 
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 

	return 0; 
}