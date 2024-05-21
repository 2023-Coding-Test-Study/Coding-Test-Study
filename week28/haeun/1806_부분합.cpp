#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, S; 
	cin >> N >> S; 

	vector<int> v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}

	int l = 0, r = 0;
	int ans = 1e9, sum = 0; 

	// sum: v[l] ~ v[r - 1]까지의 부분합 
	while(l <= r && r <= N){
		if(sum >= S){
			// 부분 수열의 길이의 최솟값 
			ans = min(ans, r - l);
			sum -= v[l++];
		}else{
			if(r == N) break;
			sum += v[r++];
		}
	}

	if(ans == 1e9) cout << "0\n";
	else cout << ans;

	return 0;
}