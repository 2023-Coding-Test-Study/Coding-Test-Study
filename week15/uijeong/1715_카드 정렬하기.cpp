#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        pq.push(temp);
    }

    int ans = 0;
    while (pq.size() != 1) { // 더할 두 카드 묶음이 없음! 
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    cout << ans;
}
