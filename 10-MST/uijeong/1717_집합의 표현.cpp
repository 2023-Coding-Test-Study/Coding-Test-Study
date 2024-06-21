#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> p;

int find(int x) { // 루트 노드 찾아주는 연산 
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void addSet(int a, int b) { // 합집합 
    int u = find(a);
    int v = find(b); // 각 루트노드를 찾아준 후 

    if (u == v) return; // 이미 같은 집합이면 종료

    // 루트 노드 연결 
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i <= N; i++) p.push_back(i); // 초기화 

    for (int i = 0; i < M; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 0) {
            // 합집합 해라 
            addSet(a, b);
        }
        else{
            if (find(a) == find(b)) cout << "YES";
            else cout << "NO";
            cout << "\n";
        }
    }
}
