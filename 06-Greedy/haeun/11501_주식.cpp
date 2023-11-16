#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
	  int N;
	  cin >> N;
	  
	  vector<int> stocks;
	  for (int i = 0; i < N; i++) {
		  int x;
		  cin >> x;
		  stocks.push_back(x);
	  }

	  long long total = 0; 
	  int currentMax = -1; 
	  
	  for(int i = N - 1; i >= 0; i--){
		  currentMax = max(stocks[i], currentMax); 

		  // 최댓값보다 현재 주가가 낮으면 그 차이값이 이익이 된다. 
		  total += currentMax - stocks[i];
	  }

	  cout << total << "\n"; 
  }

  return 0;
}
