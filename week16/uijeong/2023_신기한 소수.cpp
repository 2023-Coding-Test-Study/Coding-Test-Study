#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> ans;
int f[4] = { 2, 3, 5, 7 }; 

void dfs(string s) {
    if (s.size() == N) {
        ans.push_back(s);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        s.push_back(i);
        bool isPrime = true;
        for (int j = 2; j <= sqrt(stoi(s)); j++) {
            if (stoi(s) % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            dfs(s);
        }
        s.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < 4; i++) {
        string s = "";
        s.push_back(f[i]);
        dfs(s);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}
