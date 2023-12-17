#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> p(201, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void addSubset(int a, int b) {
    int u = find(a);
    int v = find(b);

    if (u == v) return; // 이미 같은 그룹인 경우 

    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int temp;
            cin >> temp;

            if (temp == 1) { // 연결 된 경우 
                addSubset(i, j); // 같은 그룹으로 합쳐주기 
            }
        }
    }

    int city = 0; // 현재 도시
    int temp = 0; // 현재 루트 노드
    cin >> city;
    temp = find(city);
    for (int i = 1; i < M; i++) {
        cin >> city;
        if (temp != find(city)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
