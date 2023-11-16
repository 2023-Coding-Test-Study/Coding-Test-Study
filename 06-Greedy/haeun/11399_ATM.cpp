#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N; 
vector<pair<int, int>> arr; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; 

	for(int i = 0; i < N; i++){
		int time; 
		cin >> time; 
		
		arr.push_back({time, i}); 
	}

	sort(arr.begin(), arr.end());

	int sum = 0; 
	for(int i = 1; i <= N; i++){
		int time = arr[i - 1].first; 
		sum += time * (N - i + 1); 
	}

	cout << sum; 

	return 0; 
}