#include <bits/stdc++.h>
using namespace std;

int N;
long long S;
int ans;
vector<int> seq;
long long sum = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }

    ans = N+1;
    int st = 0, ed = 0;
    while (ed <= N && st <= ed) { // 수정한 부분
        if (sum < S) { // 현재 sum이 S보다 작다면
            if (ed == N) { // 현재 st와 ed의 sum이 작고, ed는 더 이상 증가 부분 없으므로 break
                break;
            }
            sum += seq[ed++];
        }
        else { // 현재sum이 S 이상
            ans = min(ans, ed - st); // 현재 st, ed 계산 후
            sum -= seq[st++];
        }

    }

    if (ans == N+1) {
        cout << 0;
        return 0;
    }

    cout << ans;
}
