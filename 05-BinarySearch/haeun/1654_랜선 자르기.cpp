#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll; 

const int MAX = 10001; 
ll lines[MAX];
int K, N;

// 자르는 랜선 길이가 x일 때, 나오는 개수가 N개 이상인가?
bool decision(ll x){ 
	ll sum = 0; 
	for(int i = 0; i < K; i++){
		sum += lines[i] / x; 
	}
	return sum >= N;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N; 

	for(int i = 0; i < K; i++){
		cin >> lines[i]; 
	}

	sort(lines, lines + K);
	ll left = 1; // 1부터 시작하는 것에 유의 
	ll right = lines[K - 1];

	ll ans = 0; 
	while(left <= right){
		ll mid = (left + right) / 2;
		
		if(decision(mid)) {
			ans = max(ans, mid); 
			left = mid + 1; 
		}
		else right = mid - 1; 
	}

	// 결정 문제를 만족시키는 x의 최댓값 출력 
	cout << ans;  

	return 0;
}
