#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring> 
#include <queue> 
using namespace std; 

const int MAX = 12;
int arr[MAX]; // 피연산자의 값 저장 

const int NUM = 4; 
int operators[NUM]; // 연산자의 개수 저장 

int N;
int maxVal = -1e9, minVal = 1e9; 

void input(){
	cin >> N; 

	for(int i = 0; i < N; i++){
		cin >> arr[i]; 
	}

	for(int i = 0; i < NUM; i++){
		cin >> operators[i]; 
	}
}

// idx    - 다음으로 연산할 숫자의 인덱스
// result - 현재까지의 연산 결과
void dfs(int idx, int result){ 
	// n개의 피연산자에 대한 한가지 연산 결과가 나오면 
	// 최댓값, 최솟값 갱신하기  
	if(idx == N){ 
		maxVal = max(maxVal, result);
		minVal = min(minVal, result);
		return; 
	} 

	for(int i = 0; i < 4; i++){ 
		// 현재 연산자를 다 사용한 경우, 다음 연산자로 패스 
		if(operators[i] <= 0) continue;

		operators[i]--; // 연산자 사용 

		switch(i){ // 재귀 호출 
			case 0: 
				dfs(idx + 1, result + arr[idx]);
				break; 
			case 1: 
				dfs(idx + 1, result - arr[idx]); 
				break; 
			case 2: 
				dfs(idx + 1, result * arr[idx]); 
				break;
			case 3: 
				dfs(idx + 1, result / arr[idx]); 
				break; 
		}

		operators[i]++; // 다른 경우의 수를 위해 상태 복구 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	dfs(1, arr[0]); 

	cout << maxVal << "\n" << minVal; 

	return 0;
}
