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

int N; 
vector<int> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++){
		int x; 
		cin >> x; 
		arr.push_back(x);
	}

	// 시간 순으로 정렬 
	sort(arr.begin(), arr.end());

	vector<int> psum(N, 0);
	for(int i = 0; i < N; i++){
		if(i == 0) psum[i] = arr[i];
		else psum[i] = psum[i - 1] + arr[i];
	}

	int total = 0; 
	for(int i = 0; i < N; i++){
		total += psum[i];
	}
	cout << total; 
	
	return 0;
}