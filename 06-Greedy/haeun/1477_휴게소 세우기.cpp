#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N, M, L; 
vector<int> arr; 

// 아직 휴게소가 세워지지 않은 구간에 
// x의 간격으로 휴게소를 세울 때, 
// 새로 세운 휴게소의 개수가 M보다 많은가? 
bool decision(int x){
	int cnt = 0; // 새로 세운 휴게소의 개수 
	
	for(int i = 1; i < arr.size(); i++){
		// 휴게소가 세워지지 않은 구간에 
		int dist = arr[i] - arr[i - 1];

		// x의 간격으로 새 휴게소를 세운다. 
		cnt += dist / x;

		// 휴게소 위치가 중복될 수 없으므로 개수 조정 
		if(dist % x == 0) cnt--;
	}
	
	return cnt > M; 
}

int main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);

	cin >> N >> M >> L; 

	// 고속도로의 시작과 끝에는 휴게소를 세울 수 없다.
	arr.push_back(0);
	arr.push_back(L);
	
	// 기존 휴게소의 위치 입력 
	for(int i = 0; i < N; i++){
		int x; 
		cin >> x; 
		arr.push_back(x); 
	}

	// 이분탐색 전에 정렬 먼저!! 
	sort(arr.begin(), arr.end()); 

	int left = 1; 
	int right = L; 

	// 휴게소 간 거리의 최댓값의 최솟값
	int ans = 0;  

	while(left <= right){
		int mid = (left + right) / 2; 

		if(decision(mid)){
			left = mid + 1; 
		}else{
			ans = mid; 
			right = mid - 1; 
		}
	}

	cout << ans; 
	
  	return 0;
}
