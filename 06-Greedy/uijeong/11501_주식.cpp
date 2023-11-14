#include <bits/stdc++.h>
using namespace std;

int N;
int money[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T = 0;
    cin >> T;

    int sum = 0;
    for (int i = 0; i < T; i++) {
        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> money[j];
        }

        int max = 0;
        long long sum = 0;

        for (int day = N-1; day >= 0; day--) {
            if (max < money[day]) { // 현재 값이 temp 보다 크면 max로 결정
                max = money[day];
            }
            else { // 작거나 같으면 
                sum += (max - money[day]); // 더해준다.
            }
        }

        cout << sum << "\n";
    }
}
