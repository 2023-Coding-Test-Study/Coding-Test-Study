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

ll N, K;

// x보다 작거나 같은 원소가 몇 개인가? 
ll getLowerCount(ll x) {
	ll sum = 0;
	for(int i = 1; i <= N; i++){
		sum += min(x / i, (ll)N);
	}
	return sum; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	
	ll left = 1, right = N * N;
	ll ans = 0;
	
	while(left <= right){
		ll mid = (left + right) / 2; 

		if(getLowerCount(mid) >= K){
			ans = mid; 
			right = mid - 1;
		}else{
			left = mid + 1; 
		}
	}

	cout << ans;
	
	return 0;
}