#include <bits/stdc++.h>
using namespace std;

int N;
int A[16]; // 금액
int T[16]; // 상담기간 
int D[16]; // 최종 금액

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> A[i];
    }

    for (int i = N; i > 0; i--) {
        int day = i + T[i];
        if (day > N + 1) { // 기간이 넘어간다면 취소
            D[i] = D[i + 1];
        }
        else {
            D[i] = max(D[i + 1], D[day] + A[i]); // i일자 포함 X or i일자 포함 + 포함 후 날짜
        }
    }
    
    cout << D[1];

}
