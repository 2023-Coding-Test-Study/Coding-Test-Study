#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map> 
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

const int MAX = 1001; 
int N, K;
ll dp[MAX][MAX];

void input() {
	cin >> N >> K;
}

void solution() {
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= K; j++){ 
			if(j == 0 || i == j) dp[i][j] = 1; 
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; 
		}
	}

	cout << dp[N][K]; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 
	
	return 0;
}
