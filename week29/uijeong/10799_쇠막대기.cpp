#include <bits/stdc++.h>

using namespace std;

stack<int> s; // 스택 
string str; // 인풋
int str_s = 0; // 길이
int ans = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    str_s = str.length();
    for (int i = 0; i < str_s; i++) {
        if (str[i] == '(') { // 현재 문자열이 '(' 일 때
            s.push(1);
        }
        else { // 현재 문자열이 ')' 일 때
            s.pop(); 
            if(str[i-1] == '(') { // 레이저일 때 
                ans += s.size(); // 현재 막대기 개수 더하기
            }
            else { // 막대기일 때 
                ans++;
            }
        }
    }

    cout << ans;
}
