#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C, M;
	cin >> A >> B >> C >> M;

	int sum = 0;
	int count = 0;

	for (int i = 0; i < 24; i++) {
		if (M - sum >= A) {
			sum += A;
			count++;
		}
		else {
			sum -= C;
			if (sum < 0) { // 이거 없으면 틀림 -> 당연하지
				sum = 0;
			}
		}
	}

	cout << B * count;
}
