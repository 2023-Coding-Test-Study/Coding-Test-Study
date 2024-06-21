
#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

int T, N, D, C;
const int INF = 1e9;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        // 테스트 케이스에 대해서 초기화 
        vector<pair<int, int>> adj[10001];
        int d[10001];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        fill(d + 1, d + N + 1, INF); // 초기화 

        cin >> N >> D >> C;
        while (D--) {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back({ s, a }); // 시간, 정점
        }

        d[C] = 0; // 감염되는데 0초 
        pq.push({ 0, C });
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if (d[cur.Y] != cur.first) continue; // 이미 확정된 정점을 방문했다면 넘어가기  
            for (auto nxt : adj[cur.Y]) {
                if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; // 굳이 확정된 정점을 거쳐서 갈 필요가 없으면
                d[nxt.Y] = d[cur.Y] + nxt.X; 
                pq.push({ d[nxt.Y], nxt.X }); 
            }
        }
        
        int count = 0;
        int sec = 0;
        for (int i = 1; i <= N; i++) {
            if (d[i] == INF) continue;
            count++;
            if (d[i] > sec) sec = d[i]; // 최댓값인 경우 
        }
        cout << count << " " << sec << "\n";

    }

    return 0;
}
