#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[1001]; // 그래프 간선 (비용, 정점) 
int d[1001]; // 거리 가중치를 담은 배열 
const int INF = 2147483647;
int dp[1001]; // dp 테이블 


int find_route(int now) {
	// 해당 노드를 선택한 것만으로도 방향성 존재
	// 즉 거리가 큰 순에서 작은 순으로 선택하므로 절대 반대 방향으로 선택할 일 없음
	// 한 번 dp를 계산하면 다시 계산할 일 없음
	if (now == 2) return 1;
	if (dp[now] != 0) return dp[now];

	for (auto nxt : adj[now]) {
		// 해당 간선에 대해서 
		if (d[nxt.second] < d[now]) {
			dp[now] += find_route(nxt.second);
		}
	}
	return dp[now];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	fill(d, d + 1001, INF); // 초기화 
	for (int i = 0; i < M; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		adj[a].push_back({ v, b });
		adj[b].push_back({ v, a }); // 양방향이므로 
	} // 그래프 입력 

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // 비용이 작은 정점부터 선택하기 위함 
	d[2] = 0; // 자기자신이므로
	q.push({ 0, 2 });
	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		int node = cur.second;
		if (d[node] != cur.first) continue; // 즉 확정된 노드에 대해서만 처리, 고로 d[node]는 이미 최단거리 확정, cur은 불필요

		for (auto nxt : adj[node]) { // 해당 node와 연결된 나머지 정점에 대해서 
			if (d[nxt.second] <= d[node] + nxt.first) continue; // 해당 node를 거쳐서 가는 것 보다 기존의 최단거리가 더 짧으므로 업데이트 X 
			d[nxt.second] = d[node] + nxt.first;
			q.push({ d[nxt.second], nxt.second });
		}
	} // 2번 정점에 대한 최단거리 도출 

	cout << find_route(1); // 합리적인 이동경로 찾기 
}
