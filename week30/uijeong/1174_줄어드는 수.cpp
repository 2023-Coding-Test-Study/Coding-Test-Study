#include <bits/stdc++.h>

using namespace std;
int N;
vector <long long> v;

void dfs(long long num, int level) {
    if (level > 10) return;
    v.push_back(num);
    for (int i = num % 10 - 1; i >= 0; i--) {
        dfs(num * 10 + i, level + 1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i <= 9; i++)
        dfs(i, 1);
    sort(v.begin(), v.end());

    if (N > v.size()) {
        cout << "-1";
    }
    else cout << v[N - 1];
}
