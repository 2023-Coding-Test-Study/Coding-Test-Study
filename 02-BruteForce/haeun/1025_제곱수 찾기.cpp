#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<string> arr;
int answer = -1;

int isPerfectSquare(int num) { 
	int sqrtNum = sqrt(num); 
	if(sqrtNum * sqrtNum == num){
		return num; 
	} 
	return -1; 
}

void calcMaxPerfectSquare(int i, int j){
	// dr: 행의 공차
	for(int dr = -N + 1; dr < N; dr++){
		// dc: 열의 공차 
		for(int dc = -M + 1; dc < M; dc++){
			// 공차가 모두 0인 경우, 아래 while문에서 무한 루프 
			if(dr == 0 && dc == 0) continue; 

			// 현재 dr, dc로 나올 수 있는 모든 수열에 대해 
			// 완전 제곱수인지 검사 
			int row = i, col = j;
			string temp = "";

			while(0 <= row && row < N && 0 <= col && col < M){
				temp += arr[row][col];
				answer = max(answer, isPerfectSquare(stoi(temp)));

				row += dr; 
				col += dc; 
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		string str; 
		cin >> str; 
		arr.push_back(str); 
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			calcMaxPerfectSquare(i, j);
		}
	}

	// N, M 모두 1인 경우에는 dr, dc가 0이어서 
	// while문에 진입하지 않으므로 따로 검사해준다. 
	if(N == 1 && M == 1){
		// 형변환 주의!!! 
		int num = arr[0][0] - '0'; 

		// 완전 제곱수 아니면 -1 출력 
		cout << isPerfectSquare(num); 
		
		return 0; 
	}

	cout << answer; 

	return 0;
}
