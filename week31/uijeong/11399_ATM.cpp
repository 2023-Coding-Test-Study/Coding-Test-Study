#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp1;
        cin >> temp1;
        v.push_back(temp1);
    }

    sort(v.begin(), v.end()); // 오름차순 정렬

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i] * (N - i);
    }

    cout << sum;
}
