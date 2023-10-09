#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	priority_queue<int, vector<int>, greater<int>>  q;

	cin >> N;
	int temp = 0;

	for (int i = 0; i < N; i++) {
		cin >> temp;

		if (temp == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << q.top() << "\n";
			q.pop();
		}
		else {
			q.push(temp);
		}
	}
}
