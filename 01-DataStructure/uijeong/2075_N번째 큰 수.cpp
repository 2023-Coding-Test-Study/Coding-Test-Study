#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	priority_queue<int, vector<int>, greater<int>>  q;

	cin >> N;
	int temp = 0;

	for (int i = 0; i < N*N; i++) {
		cin >> temp;

		if (i >= N) {
			if (q.top() < temp) {
				q.pop();
				q.push(temp);
			}
			continue;
		}
		
		q.push(temp);
	}

	cout << q.top();
}
