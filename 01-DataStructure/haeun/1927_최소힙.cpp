#include <iostream>
#include <queue> 
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	// 최소 힙 
	priority_queue<int, vector<int>, greater<int>> pq; 

	int n; 
	cin >> n; 

	// O(NlogN): N은 최대 10만 
	for(int i = 0; i < n; i++){
		int x; 
		cin >> x; 

		if(x == 0){
			if(!pq.empty()){
				cout << pq.top() << "\n"; // O(1)
				pq.pop(); // O(logN)
			}else{
				cout << "0\n"; 
			}
		}else{
			pq.push(x); // O(logN)
		}
	}
	
	return 0;
}