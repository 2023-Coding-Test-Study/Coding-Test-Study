#include <bits/stdc++.h>
using namespace std;

int N;
pair<long, long> town[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long sum = 0;
    long long count = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> town[i].first >> town[i].second;
        sum += town[i].second;
    }

    sort(town, town+N); // first를 기준으로 오름차순 

    for (int i = 0; i < N; i++) {
        count += town[i].second;
        if (count >= (sum + 1) / 2) {
            // sum+1을 해주어야 3/2 = 1이 안 된다
            cout << town[i].first;
            break;
        }
    }
}
