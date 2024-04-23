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

int n; 
vector<ll> arr; 

void solution() {
	if(n >= 0 && n <= 9){
		cout << n << endl;
		return; 
	}
	
	queue<ll> q;
	for(int i = 0; i <= 9; i++){
		q.push(i);
		arr.push_back(i);
	}

	while(!q.empty()){
		ll num = q.front(); 
		q.pop();

		int last = num % 10; 
		for(int i = 0; i < last; i++){
			ll nextNum = num * 10 + i; 
			q.push(nextNum);
			arr.push_back(nextNum);
		}
	}

	if(n >= arr.size()){
		cout << -1;
	}else{
		cout << arr[n];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	solution();
	
	return 0;
}