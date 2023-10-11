#include <iostream>
#include <queue> 
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	priority_queue<int> pq; // 최대 힙 

	int n; 
	cin >> n; 

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			int x; 
			cin >> x; 
			pq.push(x);
		}
	}

	// 가장 큰 수부터 n-1개의 원소 제거 
	// O(NlogN): N은 최대 1500
	for(int i = 0; i < n - 1; i++){
		pq.pop();
	}

	cout << pq.top(); 
	
	return 0;
}