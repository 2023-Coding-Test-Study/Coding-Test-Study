#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 9;
int durability[MAX];
int weight[MAX];
int N;
int ans = -1e9;

int calcBrokenEggs() {
	int cnt = 0;
	for(int i = 0; i < N; i++){ 
		if(durability[i] <= 0) cnt++; 
	}
	return cnt;
}

void dfs(int idx){
	// 한가지 경우에 대한 탐색이 종료되면 
	if(idx == N){ 
		// 깨진 계란의 개수 구하기
		int cnt = calcBrokenEggs();
		// 최댓값 갱신
		ans = max(ans, cnt);
		return; 
	}

	// 현재 계란이 깨진 경우, 다음 계란으로 이동 
	if(durability[idx] <= 0) {
		dfs(idx + 1);
		return;
	}
	
	bool flag = false;

	// 자기 자신을 제외한 모든 계란 탐색 
	for(int i = 0; i < N; i++){
		// 자기 자신이거나, 깨진 계란인 경우 
		if(idx == i || durability[i] <= 0) continue; 

		// 상태 변화 
		durability[idx] -= weight[i]; 
		durability[i] -= weight[idx];
		flag = true;

		dfs(idx + 1); // 다음 계란에 대한 탐색 

		// 상태 복구 
		durability[idx] += weight[i]; 
		durability[i] += weight[idx];
	}

	// 자신을 제외한 모든 계란이 깨져있는 경우 
	// idx를 N으로 이동시켜서 이번 경우에 대한 탐색 종료 
	if(flag == false) dfs(N);
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> durability[i] >> weight[i]; 
	}

	dfs(0); 

	cout << ans; 
	
	return 0;
}
