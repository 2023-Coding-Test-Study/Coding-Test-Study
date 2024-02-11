#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

int N;
int t[1001];
int p[1001];
int dp[1001];

void input(){
	cin >> N; 

	for(int i = 1; i <= N; i++){
		cin >> t[i] >> p[i];
	}
}

void solution() {
	for(int i = N; i > 0; i--){
		int nextDate = i + t[i];

		// 퇴사 전에 진행할 수 없으면
		if(nextDate > N + 1){
			// 이제까지 구한 최대 이익 그대로 저장 
			dp[i] = dp[i + 1];
		}else{
			// 이제까지 구한 최대 이익  
			// vs 현재 상담을 진행하여 얻을 수 있는 최대 이익
			dp[i] = max(dp[i + 1], dp[nextDate] + p[i]);
		}
	}

	// 최종해 출력 
	cout << dp[1]; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 

	return 0; 
}