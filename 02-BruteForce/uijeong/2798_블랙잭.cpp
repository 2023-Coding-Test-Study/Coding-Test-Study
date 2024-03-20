#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int sum = 0;
	int max = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];

				if (sum <= M && max <= sum) {
					max = sum;
				}
			}
		}
	}

	cout << max;
}
