#include <bits/stdc++.h>

using namespace std;

int s[100000];
int ans = 2000000001;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    sort(s, s + N); // 오름차순 정렬

    int st = 0; 
    int ed = N - 1;
    int a = st;
    int b = ed;
    while (st < ed) {
        int temp = s[st] + s[ed];
        if (abs(temp) < ans) { // 작다면
            ans = abs(temp);
            a = st;
            b = ed;
        }

        if (temp < 0) {
            st++;
        }
        else {
            ed--;
        }
    }
    cout << s[a] << " " << s[b];
}
