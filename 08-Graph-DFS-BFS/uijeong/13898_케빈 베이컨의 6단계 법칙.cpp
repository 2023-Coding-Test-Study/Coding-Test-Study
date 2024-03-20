#include <bits/stdc++.h>
using namespace std;

int adj[101][101]; // 최대 정점이 100개 
int dist[101]; // 거리 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    queue<int> q;
    int min = 0x3f3f3f;
    int ans = 0;
    for (int i = 0; i < V; i++) {
        int count = 0; // 베이컨 거리 측정
        fill(dist, dist + V, -1); // 초기화 

        q.push(i);
        dist[i] = 0; // 방문 확인
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < V; j++) {
                if (adj[i+1][j+1] == 0) continue; // 연결 안됨
                if (dist[j] != -1) continue; //이미 방문
                q.push(j);
                dist[j] = dist[cur] + 1;
                count += dist[j];
            }
        }
        // 다 계산 후 
        if (count < min) {
            ans = i;
            min = count;
        }
    }

    cout << ans+1;
}
