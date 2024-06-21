#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int edge[1001][1001];
int chk[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> edge[i][j];
        }
    }

    long long ans = 0; // 수정한 부분
    int cnt = 0; // 간선 개수 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {비용, 끝 정점}
    chk[1] = 1;
    for (int i = 2; i <= N; i++) {
        pq.push({ edge[1][i], i });
    }

    while (cnt < N - 1) {
        pair<int, int> a = pq.top(); pq.pop();
        if (chk[a.Y]) continue; // 이미 방문 시 넘어감
        chk[a.Y] = 1;
        cnt++;
        ans += a.X; // 최소 가중치 

        for (int i = 1; i <= N; i++) {
            if (i == a.Y) continue; // 같은 위치면 넘어감
            if (chk[i]) continue; // 이미 방문시 넘어감
            pq.push({ edge[a.Y][i], i });
        }
    }

    cout << ans;
}
