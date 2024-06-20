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
vector<pii> person; // 컴퓨터 이용 시작, 종료 시각

// 종료 시각, 좌석 번호 (종료 시각이 빠른 게 우선, 최소 힙)
priority_queue<pii, vector<pii>, greater<pii>> pq; 

// 비어있는 좌석 번호 (낮은 번호가 우선, 최소 힙)
priority_queue<int, vector<int>, greater<int>> seats; 

const int MAX = 100001; 
int ans[MAX]; // 각 컴퓨터의 이용자 수 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; // 최대 10만

	// 컴퓨터 이용 시작, 종료 시각 
	for(int i = 0; i < N; i++){
		int s, e;
		cin >> s >> e; 
		person.push_back({s, e});
	}

	// 시작 시간이 빠른 순으로 정렬 
	sort(person.begin(), person.end());

	// N명이 사용하기 위해 필요한 최소 컴퓨터 수 
	int num = 0;  
	
	for(auto& time: person){ 
		while(!pq.empty()){
			// 사용중인 사람의 종료 시각 vs. 다음으로 들어올 사람의 시작 시각
			int endTime = pq.top().first;
			int seatNum = pq.top().second; 
			int startTime = time.first; 

			// 이전 사용자가 이용을 종료한 경우 
			if(endTime < startTime){
				// 해당 좌석에 다음 사용자를 앉힌다. 
				seats.push(seatNum);
				pq.pop(); 
			}
			else break; 
		}

		// 초기 상태 또는 빈 좌석이 없을 때 
		if(seats.empty()){
			// 새 좌석을 만들어서 앉힌다. 
			pq.push({time.second, num}); 
			ans[num]++;
			num++;
		}else{
			// 빈 좌석이 있는 경우 
			// 가장 낮은 번호의 자리에 앉힌다. 
			int front = seats.top(); 
			pq.push({time.second, front});
			ans[front]++;
			seats.pop(); 
		}
	}

	cout << num << endl; 
	for(int i = 0; i < num; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
