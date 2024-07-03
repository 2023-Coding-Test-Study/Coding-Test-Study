#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;

	int left = 1, right = k; 
	while (left < right ) {
		int mid = (left + right ) / 2, cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
        //
		
		if (cnt < k) left = mid + 1;
		else right = mid;
	}

	cout << right << '\n';
