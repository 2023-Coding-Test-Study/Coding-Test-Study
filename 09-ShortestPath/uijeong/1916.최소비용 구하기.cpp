#include <bits/stdc++.h>
using namespace std;

int N, M;
int st, ed;
vector<pair<int, int>> adj[1001];
int fix[1001];
const int INF = 1e9+10; // 0x3f3f3f3f 하면틀림

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    fill(fix+1, fix+N+1, INF); // 초기화 
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b }); // 비용, 정점 순으로 
    }
    cin >> st >> ed;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fix[st] = 0;
    pq.push({ fix[st], st }); // 초기 위치 push
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); // 제일 최단 거리 정점 꺼내기 
        pq.pop();
        if (fix[cur.second] != cur.first) continue; // 이미 fix되었다면 넘어가기 
        for (auto nxt : adj[cur.second]) {
            if (fix[nxt.second] <= fix[cur.second] + nxt.first) continue; // 해당 최단거리로 건너는게 더 큰 경우 넘어가기
            fix[nxt.second] = fix[cur.second] + nxt.first; // 업데이트 
            pq.push({ fix[nxt.second], nxt.second}); // 해당 정점이 기준이 됨
        }
    }

    cout << fix[ed];
    return 0;
}
