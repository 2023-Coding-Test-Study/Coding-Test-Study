#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int,int>> adj[1001]; // 그래프 간선 (비용, 정점) 
int d[1001]; // 거리 가중치를 담은 배열 
const int INF = 2147483647;
bool vis[1001]; // 방문 여부 
int ans;


void dfs(int now) {
	// 해당 노드를 선택한 것만으로도 방향성 존재
	// 즉 거리가 큰 순에서 작은 순으로 선택하므로 절대 반대 방향으로 선택할 일 없음
	if (now == 2) {
		ans++;
		return;
	}
	if (vis[now]) return; // 종료 조건, 이미 방문한 경우 

	vis[now] = true;
	for (auto nxt : adj[now]) {
		// 해당 간선에 대해서 
		if (d[nxt.second] < d[now]) {
			dfs(nxt.second);
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	fill(d, d + 1001, INF); // 초기화 
	for (int i = 0; i < M; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		adj[a].push_back({v, b });
		adj[b].push_back({ v, a }); // 양방향이므로 
	} // 그래프 입력 

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q; // 비용이 작은 정점부터 선택하기 위함 
	d[2] = 0; // 자기자신이므로
	q.push({ 0, 2 });
	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		if (d[cur.second] != cur.first) continue; // 이미 값이 앞에서 업데이트 되었으므로 확정된 것 

		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; // 업데이트할 필요가 없음 
			d[nxt.second] = d[cur.second] + nxt.first;
			q.push({ d[nxt.second], nxt.second });
		}
	} // 2번 정점에 대한 최단거리 도출 
	
	dfs(1);

	cout << ans;
}
