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
vector<int> lessons;

bool decision(int x){
	int sum = 0, cnt = 0;
	
	for(auto time: lessons){
    	// x를 넘는 지점에서 cnt 갱신 
		if(sum + time > x){ 
			cnt++;
			sum = 0; 
		}
        
        // if문과 상관없이 매번 실행 
		sum += time; 
	}
	
    // for문에서 처리되지 않은 강의들에 대해 cnt 갱신
	if(sum != 0) cnt++;  
	
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
		lessons.push_back(x);
		
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