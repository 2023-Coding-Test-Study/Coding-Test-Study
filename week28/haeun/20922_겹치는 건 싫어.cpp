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

const int MAX = 100001; 
int cnt[MAX]; // 각 숫자의 등장 횟수 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k; 
	cin >> n >> k; 

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	int l = 0, r = 0;
	int ans = 0;
	
	while(l <= r && r < n){
		if(cnt[v[r]] < k){
			cnt[v[r++]]++; 
			ans = max(ans, r - l); 
		}else if(cnt[v[r]] == k){
			cnt[v[l++]]--;
		}
	}

	cout << ans; 
	
	return 0;
}