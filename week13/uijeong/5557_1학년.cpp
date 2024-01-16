#include <bits/stdc++.h>

using namespace std;

int S[101];
long long D[101][21]; // 값의 범위가 2^63이기 때문 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    // 초기값 정의 
    D[1][S[1]] = 1;

    for (int i = 2; i <= N-1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (D[i - 1][j] == 0) continue; // 해당 경우의 수는 존재하지않음
            if (j + S[i] <= 20) D[i][j + S[i]] += D[i - 1][j];
            if(j - S[i] >= 0) D[i][j - S[i]] += D[i - 1][j];
        }
    }

    cout << D[N-1][S[N]]; // N-1을 더하거나 뺐을 때 S[N]이 나오는 경우의 수 
}
