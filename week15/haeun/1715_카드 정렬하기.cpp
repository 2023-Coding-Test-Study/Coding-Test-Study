
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map> 
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

int N; 
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
	cin >> N; 
	
	for(int i = 0; i < N; i++){
		int num; 
		cin >> num; 
		pq.push(num); // 최소 힙 (오름차순 정렬)
	}
}

void solution() {
	int answer = 0;
	
	while(!pq.empty()){
		if(pq.size() == 1) break; 
		
		int first = pq.top();
		pq.pop();
		
		int second = pq.top();
		pq.pop();

		int sum = first + second;
		answer += sum;
		pq.push(sum);
	}

	cout << answer; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 

	return 0; 
}
