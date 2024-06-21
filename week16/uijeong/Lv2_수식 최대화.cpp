#include <bits/stdc++.h>
using namespace std;

vector<long long> opd; // 피연산자 
vector<int> o; // 연산자 순서
queue<int> priority; // 우선순위 담을 배열
int vis[3]; // 순서대로 +, - *
long long answer = 0;

void cal() {
    while (!priority.empty()) {
        int c = priority.front();
        if (find(o.begin(), o.end(), c) != o.end()) {
            //  존재 한다면
            int idx = find(o.begin(), o.end(), c) - o.begin(); // 인덱스 조사 
            o.erase(o.begin() + idx); // 삭제
            long long temp = 0;
            if (c == 0) {
                temp = opd[idx] + opd[idx + 1];
            }
            else if (c == 1) {
                temp = opd[idx] - opd[idx + 1];
            }
            else if (c == 2)
            {
                temp = opd[idx] * opd[idx + 1];
            }
            opd.erase(opd.begin() + idx); // 삭제
            opd.erase(opd.begin() + idx); // 삭제
            opd.insert(opd.begin() + idx, temp); // 추가 

        }
        else priority.pop();
    }

    answer = max(abs(opd[0]), answer);
}

void getAns(int cnt) {
    if (cnt == 3) { // 우선 순위 모두 결정
        cal(); // 계산 
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        priority.push(i);
        getAns(cnt + 1);
        priority.pop(); // 백!
        vis[i] = false;
    }
}

long long solution(string expression) {
    /* 문자열 분리 */
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '*') {
            o.push_back('*');
            expression[i] = ' ';
        }
        else if (expression[i] == '+') {
            o.push_back('+');
            expression[i] = ' ';
        }
        else if (expression[i] == '-') {
            o.push_back('-');
            expression[i] = ' ';
        }
    }

    int temp;
    stringstream ss;
    ss.str(expression);
    while (ss >> temp) {
        opd.push_back(temp); // 숫자 추가
        cout << temp << "\n";
    }

    getAns(0);

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution("100-200*300-500+20");
}
