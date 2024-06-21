#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

int N, M;
int chk[1001];
vector<pair<int, int>> adj[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int cnt = 0;
    for (int i = 0; i < M+1; i++) { // 간선 정보 담기 
        int cost, a, b;
        cin >> a >> b >> cost;
        adj[a].push_back({ cost, b });
        adj[b].push_back({ cost, a });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오르막길 우선 
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq2; // 내리막길 우선 
    chk[0] = 1;
    for (auto nxt : adj[0]) {
        pq.push({ nxt.X, nxt.Y });
        pq2.push({ nxt.X, nxt.Y });
    }
    
    int k1 = 0; // 오르막길 개수 
    while (cnt < N) { // 오르막길 계산 
        pair<int, int> t = pq.top(); pq.pop();
        if (chk[t.Y]) continue; // 이미 방문한 정점이면 
        cnt++;
        if (t.X == 0) k1++; // 오르막길인 경우 
        chk[t.Y] = 1; // 방문 표시 
        for (auto nxt : adj[t.Y]) {
            if (chk[nxt.Y]) continue;
            pq.push({ nxt.X, nxt.Y });
        }
    }

    int k2 = 0; // 내리막길 계산 
    fill(chk, chk + N+1, 0); // 입구 + 정점 초기화
    cnt = 0; // 초기화 
    chk[0] = 1; // 초기화
    while (cnt < N) { 
        pair<int, int> t = pq2.top(); pq2.pop();
        if (chk[t.Y]) continue; // 이미 방문한 정점이면 
        cnt++;
        if (t.X == 0) k2++; // 내리막길인 경우 
        chk[t.Y] = 1; // 방문 표시 
        for (auto nxt : adj[t.Y]) {
            if (chk[nxt.Y]) continue;
            pq2.push({ nxt.X, nxt.Y });
        }
    }

    cout << k1 * k1 - k2 * k2;
    
    return 0;
}
