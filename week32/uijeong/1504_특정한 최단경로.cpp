#include <bits/stdc++.h>

using namespace std;

int N, E; 
vector<pair<int, int>> adj[805]; // {비용, 정점 번호}를 담을 구조체 양방향임
int d[805]; // 최단 거리 테이블
const int INF = 1e9 + 10; // 무한대
int v1, v2;

void dij(int st) {
	fill(d, d + N + 1, INF); // 모두 무한대로 초기화 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선 순위 큐 정의 
	d[st] = 0; // 시작점 초기화 

	pq.push({ d[st], st }); // {0, 시작점} 추가
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // 최단 거리가 결정된 정점을 다시 방문한 경우 이 조건문에 걸림 
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; // 즉 cur를 거쳐서 가는데 더 가중치가 높으면 넘어가기 
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second }); // 업데이트 된 비용, 정점 추가 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> E;
	
	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;
		// 양방향 이므로 
		adj[u].push_back({w, v});
		adj[v].push_back({ w, u});
	}
	cin >> v1 >> v2;

	dij(v1);
	long long v1_1 = d[1];
	long long v1_n = d[N];
	long long v1_v2 = d[v2];
	dij(v2);
	long long v2_1 = d[1];
	long long v2_n = d[N];

	long long ans1 = v1_1 + v1_v2 + v2_n;
	long long ans2 = v2_1 + v1_v2 + v1_n;
	long long ans = ans1 < ans2 ? ans1 : ans2;

	if (ans >= INF) cout << -1;
	else cout << ans;
}
