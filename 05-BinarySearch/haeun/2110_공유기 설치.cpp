#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll; 

const int MAX = 200001; 
int houses[MAX];
int N, C; 

// 공유기 간의 거리가 x일 때, 
// 설치 가능한 공유기가 C개 이상인가? 
bool decision(ll x){
	ll prev = houses[0];
	int cnt = 1;
	
	for(int i = 1; i < N; i++){
		// 이전 집과의 거리가 x 이상이면 
		if(houses[i] - prev >= x){
			// 현재 위치에 공유기 설치 
			cnt++; 
			prev = houses[i]; 
		}
	}

	return cnt >= C; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C; 

	for(int i = 0; i < N; i++){
		cin >> houses[i]; 
	}

	sort(houses, houses + N);

	ll left = 1;
	ll right = houses[N - 1] - houses[0];
	ll ans = 0; 

	while(left <= right){
		ll mid = (left + right) / 2; 

		if(decision(mid)){
			ans = max(ans, mid); 
			left = mid + 1; 
		}else{
			right = mid - 1; 
		}
	}

	cout << ans; 

	return 0; 
}