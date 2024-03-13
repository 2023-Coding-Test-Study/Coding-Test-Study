#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int N_MAX = 5001; // 물건 개수 
const int M_MAX = 10001; // 상근이가 가진 돈 * 100

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(true){
		int n, m; 
		double tmp; 
		cin >> n >> tmp; 
		m = (int)(tmp * 100 + 0.5); 
		
		if(n == 0 && m == 0) break; 

		pair<int, int> candies[N_MAX];
		for(int i = 0; i < n; i++){
			cin >> candies[i].first >> tmp; 
			candies[i].second = (int)(tmp * 100 + 0.5);
		}

		int dp[M_MAX] = {0,};
		for(int i = 0; i < n; i++){
			int cal = candies[i].first; 
			int price = candies[i].second; 
			
			for(int j = price; j <= m; j++){
				dp[j] = max(dp[j], dp[j - price] + cal);
			}
		}

		cout << dp[m] << "\n";
	}
	
	return 0;
}
