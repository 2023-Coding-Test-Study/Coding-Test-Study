#include <bits/stdc++.h>

using namespace std;

int N, M; // 강의 수, 구역 수 
vector<int> lec;

bool check(int time) {
    int cnt = 0;
    int sum = 0;
    int i = 0;

    while (i < N) {
        sum += lec[i];
        if (sum > time) {
            i--;
            sum = 0;
            cnt++;
        }
        i++;
    }
    return cnt >= M;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int st = 1; // 자연수니까
    int ed = 0; // 최댓값
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        lec.push_back(temp);
        ed += temp;
    }

    while (st <= ed) { // st가 ed를 넘을 때 종료 
        int mid = (st + ed) / 2;

        if (check(mid)) { // 그룹이 같거나 많다 == 시간을 늘려야 함
            st = mid + 1;
        }
        else { // 그룹이 적다 == 시간을 줄여야 함
            ans = min(mid, ans);
            ed = mid - 1;
        }
    }

    cout << ans;
}
