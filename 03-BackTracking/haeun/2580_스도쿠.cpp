#include <iostream>
using namespace std;

const int N = 9; 
int arr[N][N]; 
bool found = false; 

bool promising(int r, int c, int num){ 
	for(int i = 0; i < N; i++){
		// 현재 행에 겹치는 숫자가 있으면 
		if(arr[r][i] == num) return false; 
		// 현재 열에 겹치는 숫자가 있으면 
		if(arr[i][c] == num) return false;
	}

	// 3x3 사각형 내에 겹치는 숫자가 있으면 
	for(int i = (r/3) * 3; i < (r/3) * 3 + 3; i++){
		for(int j = (c/3) * 3; j < (c/3) * 3 + 3; j++){
			if(arr[i][j] == num) return false; 
		}
	}

	// 모든 조건을 충족하면 true 
	return true; 
}

void dfs(int r, int c){ 
	// 행의 끝까지 오면 정답 출력 
	if(r == N){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		found = true; 
		return; 
	}

	// 열의 끝까지 오면, 다음 행의 첫번째 열로 이동 
	if(c == N) dfs(r + 1, 0); 

	// 빈칸인지 검사 
	if(arr[r][c] == 0){
		for(int i = 1; i <= N; i++){ // 1~9 
        	// 유망하다면 
			if(promising(r, c, i)){
            	// 빈칸 (r, c)에 숫자 i를 넣어본다. 
				arr[r][c] = i; 
                
                // 재귀 호출 (다음 열로 이동) 
				dfs(r, c + 1); 
                
                // (r, c)에 1~9까지의 모든 숫자를 넣을 수 없다면 
                // 이 위치로 돌아와서 상태 복구 (빈칸에 다른 숫자 넣어보기 위해서)
				arr[r][c] = 0; 
			}

			// 해를 찾고 나서 이 위치로 돌아온 경우, dfs 함수 완전히 종료 
			if(found) return; 
		}
	}else{
		// 다음 열로 이동 
		dfs(r, c + 1); 
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}

	dfs(0, 0); 

	return 0;
}