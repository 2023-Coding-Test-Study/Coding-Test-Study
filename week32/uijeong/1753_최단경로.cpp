#include <bits/stdc++.h>

using namespace std;

int V, E, S; 
vector<pair<int, int>> adj[20005]; // {비용, 정점 번호}를 담을 구조체 이떄 u -> v로 가는 간선이 여러 개일수 있다.
int d[20005]; // 최단 거리 테이블
const int INF = 1e9 + 10; // 무한대

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E >> S;
	fill(d, d + V + 1, INF); // 모두 무한대로 초기화 
	
	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선 순위 큐 정의 
	d[S] = 0; // 시작점 초기화 
	pq.push({ d[S], S }); // {0, 시작점} 추가
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // 최단 거리가 결정된 정점을 다시 방문한 경우 이 조건문에 걸림 
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; // 즉 cur를 거쳐서 가는데 더 가중치가 높으면 넘어가기 
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second }); // 업데이트 된 비용, 정점 추가 
		}
	}
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}

}
