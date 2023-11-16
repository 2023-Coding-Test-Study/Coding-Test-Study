#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll; 

int N; // 최대 10만 
vector<pii> arr;  // { 마을의 위치, 사람 수 } 
vector<ll> psum; // 사람 수의 누적 합 (좌표가 최대 10만이므로 그 합은 ll 타입)

int binarySearch() {
	int left = 0; 
	int right = N - 1; 
	int ans = 1e9; 
	
	while(left <= right){
		int mid = (left + right) / 2; 

		ll leftPeople = psum[mid]; 
		ll rightPeople = psum[N - 1] - psum[mid]; 
		
		if(leftPeople >= rightPeople){ 
			right = mid - 1; 
			ans = min(ans, arr[mid].first);
		}else{
			left = mid + 1;
		}
	}

	return ans; 
}

int main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);

	cin >> N; 

	for(int i = 0; i < N; i++){
		int pos, num; 
		cin >> pos >> num; 
		arr.push_back({pos, num}); 
	}

	// 마을의 위치를 기준으로 정렬 
	sort(arr.begin(), arr.end()); 

	// 사람 수의 누적 합 구하기 
	psum.push_back(arr[0].second);
	
	for(int i = 1; i < arr.size(); i++){
		psum.push_back(psum[i - 1] + arr[i].second); 
	}

	// 왼쪽, 오른쪽 사람들 수의 균형을 이루는 위치에 우체국 세우기 
	cout << binarySearch();
	
  	return 0;
}
