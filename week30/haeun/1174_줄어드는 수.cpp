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

int n; 
vector<ll> arr; 

void dfs(ll num, int digit){
	if(digit > 10) return; // 최대 9876543210

	arr.push_back(num);

	for(int i = 0; i < 10; i++){
		if(num % 10 > i){
			dfs(num * 10 + i, digit + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

	for(int i = 0; i < 10; i++){
		dfs(i, 1);
	}

	sort(arr.begin(), arr.end());

	// 1번째 -> arr[0]
	// ...
	// n번째 -> arr[n - 1] (size: n)
	
	if(n > arr.size()){
		cout << "-1";
	}else{
		cout << arr[n - 1];
	}
	
	return 0;
}