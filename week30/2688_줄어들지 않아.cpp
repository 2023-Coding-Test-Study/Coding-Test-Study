#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, n;
ll dp[65][10]; // i번째 자리수가 j일 때 

void fillTable(){
	for(int i = 0; i <= 9; i++){
		dp[1][i] = 1; 
	}

	for(int i = 2; i <= 64; i++){ // i번째 자리수가
		for(int j = 0; j <= 9; j++){ // j일 때
			// 가능한 단조 증가 수열의 개수를 
			// 부분 문제의 해를 모아서 구한다. 
			for(int k = j; k <= 9; k++)
				dp[i][j] += dp[i - 1][k];
		}
	}
}

void solution(){
	// n번째 자리수가 0~9일 때 
	// 가능한 단조 증가 수열의 개수 
	ll ans = 0;
	for(int i = 0; i <= 9; i++){
		ans += dp[n][i];
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fillTable();

	cin >> t;
	while(t--){
		cin >> n; 
		solution(); 
	}
	
	return 0;
}