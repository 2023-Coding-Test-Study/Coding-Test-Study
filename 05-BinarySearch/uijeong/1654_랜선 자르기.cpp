#include <bits/stdc++.h>
using namespace std;

int N, K;
int lines[10001];

bool checkN(long long s) {
    int count = 0;

    for (int i = 0; i < K; i++) {
        count += lines[i] / s; // 몫만 필요함 
    }

    return count >= N; // N개보다 많을 때 true
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> lines[i];
    }

    long long st = 1; // 길이는 자연수이기 때문에 
    long long ed = 0x7fffffff; // 2^31 -1

    while (st < ed) {
        long long mid = (st + ed + 1) / 2; // st와 ed가 1 차이나면 st가 계속 똑같아버림

        if (checkN(mid)) st = mid; // 길이를 좀 더 늘려도 됨 이때 mid여도  
        else ed = mid - 1; // mid보다 작은 길이에서 찾아야 하므로 
    }
    
    cout << st;
}
