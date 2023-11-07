#include <bits/stdc++.h>
using namespace std;

int N;
int b;
int budget[100001];

bool checkSum(int s) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        if (budget[i] >= s) {
            // 예산 이상인 경우 
            sum += s;
        }
        else {
            sum += budget[i];
        }
    }

    return sum <= b; // 합계가 맞을 때 true
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int sum = 0;
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> budget[i];
        sum += budget[i];
        m = max(m, budget[i]);
    }
    cin >> b;

    if (sum <= b) { // 주어진 예산 안이면 
        cout << m;
    }
    else {
        int st = 1;
        int ed = b;

        while (st < ed) {
            int mid = (st + ed + 1) / 2; // st와 ed가 1 차이나면 st가 계속 똑같아버림

            if (checkSum(mid)) st = mid; // 예산을 좀더 늘려도 됨
            else ed = mid - 1; // mid보다 작은 예산에서 찾아야 하므로 
        }

        cout << st;
    }
}
