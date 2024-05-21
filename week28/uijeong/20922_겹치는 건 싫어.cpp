#include <bits/stdc++.h>
using namespace std;

int N, K; 
int ans;
vector<int> seq;
int store[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }

    int st = 0, ed = 0;
    while (ed <= N-1 && st <= ed) {
        if (store[seq[ed]] < K) { // 현재 ed가 K보다 작다면
            store[seq[ed++]]++; // 현재 seq[ed]의 횟수를 증가하고 ed를 증가
            ans = max(ans, ed - st);
        }
        else { // 현재 ed가 K 이상인 경우 
            store[seq[st++]]--; // 현재 seq[st]의 횟수를 줄이고 st를 증가 
        }
    }

    cout << ans;
}
