#include <bits/stdc++.h>
using namespace std;

int paper[7];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    for (int i = 1; i <= 6; i++) {
        cin >> paper[i];
    }


    if (paper[6]) { // 0이 아니라면 
        ans += paper[6];
    }

    while (paper[5] > 0 || paper[4] > 0 || paper[3] > 0 || paper[2] > 0 || paper[1] > 0) {
        int sum = 36;
        int flag = 0;
        while (paper[5] && flag == 0) { // 반드시 1장 
            sum -= 25;
            paper[5]--;
            flag = 5;
        }
        while (paper[4] && sum >= 16 && flag == 0) { // 반드시 1장
            sum -= 16;
            paper[4]--;
            flag = 4;
        }
        while (paper[3] && sum >= 9 && (flag == 0 || flag == 3)) { // flag가 0 혹은 3일 때만 가능 
            sum -= 9;
            paper[3]--;
            flag = 3;
        }
        while (paper[2] && sum >= 4 && flag != 5) {
            if (flag == 3 && sum <= 7) break; // 예외처리!!!
            sum -= 4;
            paper[2]--;
        }
        while (paper[1] && sum >= 1) {
            sum -= 1;
            paper[1]--;
        }
        ans++;
    }

    cout << ans;
}
