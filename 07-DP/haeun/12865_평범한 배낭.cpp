#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N_MAX = 101; 
const int K_MAX = 100001; 
int dp[N_MAX][K_MAX];
int weight[N_MAX];
int value[N_MAX];

int main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);

	// 물건의 개수, 배낭의 용량
	int N, K; 
	cin >> N >> K;

	// 물건 N개의 무게와 가치 (인덱스 주의)
	for(int i = 1; i <= N; i++){ 
		cin >> weight[i] >> value[i]; 
	}

	// 어떤 물건도 담지 않는 경우
	for(int i = 0; i <= K; i++){
		dp[0][i] = 0;
	}
	
	// 배낭 용량이 0인 경우
	for(int i = 0; i <= N; i++){
		dp[i][0] = 0; 
	}

	for(int i = 1; i <= N; i++){ // 물건 1~i까지 고려 
		for(int w = 1; w <= K; w++){ // 배낭의 용량 1~K 
			int wi = weight[i]; 
			int vi = value[i]; 

			// i번째 물건의 무게가 현재 배낭 용량보다 큰 경우 
			if(wi > w) {
				// (i-1)번째 물건까지만 담는다. 
				dp[i][w] = dp[i - 1][w];
			}else{
				// i번째 물건을 담을지 말지 결정한다. 
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wi] + vi); 
			}
		}
	}

	// 배낭에 넣을 수 있는 물건 가치의 최댓값 
	cout << dp[N][K]; 
	
  	return 0;
}
