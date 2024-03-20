#include <bits/stdc++.h>

using namespace std;

int d[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;

    cin >> a >> b;
    int a_s = a.size();
    int b_s = b.size();
    
    for (int i = 1; i <= a_s; i++) {
        for (int j = 1; j <= b_s; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } 
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = a_s;
    int j = b_s;
    while (d[i][j]) {
        if (d[i][j] == d[i][j-1]) {  // 위의 숫자랑 같으면
            j--;
        }
        else if (d[i][j] == d[i - 1][j]) { // 왼쪽 숫자랑 같으면
            i--;
        }
        else { // 둘 다 다른 경우 해당 문자가 같은 경우! 
            ans += a[i-1]; // 문자열은 0-index이기 때문
            i--; j--;
        }
    }

    cout << d[a_s][b_s] << "\n";
    if (ans.size() > 0) {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}
