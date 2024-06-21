#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int N, K; // 샘물의 개수, 집의 개수 
unordered_set<int> vis; // 방문 표시 
long long ans = 0; // 최종 거리 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	queue<int> q;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
		vis.insert(temp); // 해당 위치도 방문 표시 
	} // 샘물 위치 저장

	long long dist = 1; // 샘물과의 거리
	while (!q.empty()) {
		int size = q.size(); // 현재 큐의 원소 개수 저장 (초기 = 샘물의 개수)
		while (size > 0) { // 같은 거리를 측정하기 위한 조건 
			auto cur = q.front(); q.pop();
			size--; // 큐의 원소 

			for (int i : { cur - 1, cur + 1 }) {
				if (vis.count(i) >= 1) continue; // 이미 방문했다면 넘어가기 
				ans += dist; // 거리 합 
				q.push(i);
				// 집 하나 추가 
				vis.insert(i); 
				K--; 
				if (K == 0) { // 반드시 이곳에 위치, 집을 다 만들었다면 종료 
					cout << ans;
					return 0;
				}
			}
		}
		dist++; // 거리 업데이트 
	}
}
