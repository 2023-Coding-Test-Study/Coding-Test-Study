#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000001; 
int tree[MAX]; 
int N, M;

// 절단기 높이가 x일 때, 잘린 나무 길이의 합이 M 이상인가?
bool decision(int x){
	long long total = 0; 

	for(int i = 0; i < N; i++){
		int gap = tree[i] - x; 
		if(gap > 0){
			total += gap; 
		}
	}

	return total >= M; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; 

	for(int i = 0; i < N; i++){
		cin >> tree[i]; 
	}

	sort(tree, tree + N); 
	int left = 0;
	int right = tree[N - 1];
	
	int ans = 0;
	while(left <= right){
		int mid = (left + right) / 2; 
		
		if(decision(mid)) { 
			ans = max(ans, mid); 

			// true 구간의 최댓값을 구하기 위해 
			left = mid + 1; 
		}
		// 포인터가 true 구간으로 이동하도록 
		else right = mid - 1; 
	}

	// 결정 문제를 만족시키는 x의 최댓값 출력 
	cout << ans; 

	return 0;
}
