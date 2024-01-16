#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

const int N_MAX = 101; 
const int V_MAX = 21; 
ll dp[N_MAX][V_MAX];
ll arr[N_MAX];
int N; 

void input() {
	cin >> N; 

	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
}

ll dfs(int idx, int sum){
	if(sum < 0 || sum > 20) return 0; 

    // 복사 연산 수행하지 않도록 reference 사용
	ll& result = dp[idx][sum]; 
	if(result != 0) return result;

	if(idx == N - 2){
		if(arr[N - 1] == sum){
			return 1; 
		}
		return 0; 
	}

	result += dfs(idx + 1, sum + arr[idx + 1]);
	result += dfs(idx + 1, sum - arr[idx + 1]);

	return result; 
}

void solution() {
	cout << dfs(0, arr[0]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 
}