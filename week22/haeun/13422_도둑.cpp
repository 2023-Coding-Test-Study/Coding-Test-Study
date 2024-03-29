#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll; 
typedef pair<int, int> pii;

const int MAX = 100001; 
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, m, k; 

	cin >> t; 
	while(t--){ 
		cin >> n >> m >> k; 

		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		int ans = 0, sum = 0; 
		int start = 0, end = m - 1; 
		for(int i = 0; i < m; i++){
			sum += arr[i];
		}

		if(n == m){ // 예외 처리
			cout << (sum < k ? 1 : 0) << "\n";
			continue; 
		}

		while(true){
			if(sum < k) ans++; 

			sum -= arr[start];
			start++; 
			end++; 

			if(end >= n) end = 0; 
			if(end == m - 1) break; 

			sum += arr[end];
		}

		cout << ans << "\n";
	}
	
	return 0;
}
