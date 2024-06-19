#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 7;
int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX][3]; 
int dc[] = {-1, 0, 1};
int ans = 1e9;

void input() {
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j]; 
		}
	}
}

int dfs(int r, int c, int prevDir){
	// 달에 도착한 경우 
	if(r == N) return 0;
	
	// dp 테이블의 원소에 대한 참조 변수 정의 
	int& result = dp[r][c][prevDir];

	// 테이블에 저장된 값이 있으면 그대로 사용 
	if(result != 0) {
		return result;
	}

	// 세가지 방향 중에 최소 연료 비용 저장 
	result = 1e9;
	for(int i = 0; i < 3; i++){
		int nr = r + 1; 
		int nc = c + dc[i]; 
		if(nc < 0 || nc >= M) continue;

		// 이전 칸의 이동 방향과 같은 경우 패스 
		if(prevDir == i) continue; 

		// 재귀호출 할 때마다 dp 테이블에 결과 저장 
		int nextCost = dfs(nr, nc, i);
		result = min(result, arr[r][c] + nextCost); 
	}

	return result;
}

void solution() {
	// M개의 열에 대해 최소 비용 구하기 
	for(int i = 0; i < M; i++){
		ans = min(ans, dfs(0, i, -1));
	}
	cout << ans; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution(); 
	
	return 0;
}