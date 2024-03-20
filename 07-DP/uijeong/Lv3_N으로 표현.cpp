#include <bits/stdc++.h>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    set<int> dp[8]; // 중복 제거를 위해 
    
    // N을 나열해서만 수를 표현한 경우
    int num = 0;
    for (int i = 0; i < 8; i++) {
        num = 10 * num + N; // 십진수이므로 
        dp[i].insert(num); // set에 추가 
    }
    
    // DP[i] = DP[i-1] + DP[i-j-1] (0 <= j < i)
    for (int i = 1; i < 8; i++) { // 8개의 N으로 수를 표현
        for (int j = 0; j < i; j++) { 
            for (int a : dp[j]) { // dp[j]의 첫 번째 부터 마지막까지 순회 
                for (int b : dp[i - j - 1]) { 
                    dp[i].insert(a + b); // 사칙 연산 추가
                    dp[i].insert(a - b); // 사칙 연산 추가 
                    dp[i].insert(a * b); // 사칙 연산 추가 
                    if (b != 0) { // 분모가 0이 되면 안 됨
                        dp[i].insert(a / b);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if (dp[i].count(number)) { // 12라는 숫자가 몇 개 있는지 찾기 
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}
