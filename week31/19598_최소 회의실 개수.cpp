#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;

// 회의 시작 시간을 기준으로 한 최소 힙
priority_queue<pii, vector<pii>, greater<>> pq;

// 회의 종료 시간을 기준으로 한 최소 힙 
priority_queue<int, vector<int>, greater<>> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++){
		int s, e;
		cin >> s >> e; 
		pq.push({s, e});
	}

	// 시작 시간이 가장 빠른 원소 추가 
	ans.push(pq.top().second);
	pq.pop();

	while(!pq.empty()){
		pii now = pq.top();
		int prevEndTime = ans.top();
		int curStartTime = now.first;

		if(prevEndTime <= curStartTime){
        	ans.pop(); // 이전 원소 제거 
			ans.push(now.second); // 새 원소 추가 
		}else{
			ans.push(now.second);
		}

		pq.pop();
	}

	cout << ans.size(); 
	
	return 0;
}