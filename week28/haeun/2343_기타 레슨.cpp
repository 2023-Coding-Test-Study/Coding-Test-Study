#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M; 
queue<int> lessons;

// 블루레이 크기가 x일 때 
// N개의 강의를 담기 위해 필요한 개수는 M개 이하인가?
bool decision(int x){
	queue<int> q(lessons); // 원소 전체 복사 
	
	int sum = 0, cnt = 0;
	while(!q.empty()){
		if(sum + q.front() <= x){ 
			sum += q.front(); 
			q.pop(); 
			if(q.empty()) cnt++; 
		}else{
			cnt++; 
			sum = 0; 
		}
	}
	
	return cnt <= M;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; 

	int sum = 0;
	int longestLesson = 0;
	
	for(int i = 0; i < N; i++){
		int x; 
		cin >> x;
		lessons.push(x);
		
		sum += x;
		longestLesson = max(x, longestLesson);
	}

	int left = longestLesson; // 크기의 최솟값 
	int right = sum; // 크기의 최댓값 -> 개수 1 
	
	int ans = 1e9;
	while(left <= right){
		int mid = (left + right) / 2;
		if(decision(mid)){
			ans = min(ans, mid);
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	
	cout << ans;
	
	return 0;
}