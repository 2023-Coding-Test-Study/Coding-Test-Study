#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001; 
int arr[MAX]; 
int dp[MAX]; 
int maxLength = 0; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; 
	cin >> N; 
	
	for(int i = 0; i < N; i++){
		cin >> arr[i]; 
	}

	for (int i = 0; i < N; i++) {
		int tmp = 0;

		// i보다 앞쪽에 있으면서  
		for (int j = 0; j < i; j++) {
			// i번째 값보다 작은 원소들 중에 
			if (arr[j] < arr[i]) {
				// dp 테이블의 최댓값 구하기 
				tmp = max(tmp, dp[j]);
			}
		}

		dp[i] = tmp + 1; // 거기에 1을 더해서 dp 테이블 갱신 
		maxLength = max(dp[i], maxLength); // dp 테이블의 최댓값 갱신 
	}

	cout << maxLength; 

	return 0;
}