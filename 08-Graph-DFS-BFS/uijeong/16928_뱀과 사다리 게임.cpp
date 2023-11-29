#include <bits/stdc++.h>
using namespace std;

int adj[101]; // 최대 정점이 100개 
int dist[101]; // 거리 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u] = v; // 사다리와 뱀 담기
    }

    fill(dist, dist + 101, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0; // 방문 확인

    while (dist[100] == -1) {
        int cur = q.front();
        q.pop();

        for (int i = cur + 1; i <= cur + 6; i++) {
            if (i > 100) break;
            if (dist[i] != -1) continue; // 이미 방문 했으면 넘어감! 
            if (adj[i] < i && adj[i] != 0) continue; // 뱀의 노드인 경우 넘어감! 
            else if (adj[i] > i) {
                // 사다리인 경우
                q.push(adj[i]); // 큐에 담고 방문 표시
								dist[adj[i]] = dist[cur]; 
            }
            else {
                // 아무런 연결이 없는 경우
                q.push(i);
								dist[i] = dist[cur] + 1;
            }
        }
    }
    cout << dist[100];
}
