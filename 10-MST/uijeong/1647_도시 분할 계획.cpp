#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> p(100001, -1);
tuple<int, int, int> edge[1000005];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int isDiffGroup(int a, int b) {
    // 같은 그룹인지 확인 후 더해줌
    int u = find(a);
    int v = find(b);

    if (u == v) return 0; // 같은 그룹

    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int cost, a, b;
        cin >> a >> b >> cost;
        edge[i] = { cost, a, b };
    }

    sort(edge, edge + M); // 오름차순 정렬 
    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < M; i++) {
        if (N == 2) break; // 만약 마을이 2개인 경우 연결 필요 없음
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!isDiffGroup(a, b)) continue;
        ans += cost;
        cnt++;
        if (cnt == N - 2) break;
    }

    cout << ans;
}
