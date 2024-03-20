#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10001;
int budgets[MAX];
int N, M;

// 각 지방에 배정된 예산이 x일 때, 
// 총 예산이 M 이하인가? 
bool decision(int x){
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum += min(budgets[i], x);
	}
	return sum <= M; 
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; // 지방의 수 

	for(int i = 0; i < N; i++){
		cin >> budgets[i]; 
	}

	cin >> M; // 총 예산 

	sort(budgets, budgets + N);
	
	int left = 0; 
	int right = budgets[N - 1]; 
	int ans = 0;
	
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(decision(mid)) {
			// 현재까지의 최댓값 저장 
			ans = mid;
			
			// 더 큰 값을 찾으러 탐색 
			left = mid + 1;
		}
		// 총 예산이 M을 넘지 않도록 
		else right = mid - 1; 
	}

	cout << ans; 
	
	return 0;
}
