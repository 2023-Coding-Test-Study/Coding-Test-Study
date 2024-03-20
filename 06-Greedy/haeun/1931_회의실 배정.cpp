#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

bool compare(pii a, pii b){
	if(a.second == b.second) return a.first < b.first; 
	return a.second < b.second;
}

int main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);

	int N; 
	cin >> N; 

	vector<pii> meetings; 
	for(int i = 0; i < N; i++){
		int start, end;
		cin >> start >> end;
		meetings.push_back({start, end});
	}

	// 종료 시간 기준으로 오름차순 정렬
	sort(meetings.begin(), meetings.end(), compare);

	// 종료 시간이 가장 빠른 회의부터 시작 
	int prevEndTime = meetings[0].second; 
	int count = 1;

	for(int i = 1; i < meetings.size(); i++){
		// 현재 회의의 시작 시간 >= 이전 회의의 종료 시간 
		if(meetings[i].first >= prevEndTime){
			prevEndTime = meetings[i].second; 
			count++; 
		}
	}

	cout << count; 
	
  	return 0;
}
