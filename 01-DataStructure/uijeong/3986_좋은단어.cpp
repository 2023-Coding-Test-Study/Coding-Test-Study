#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	string text;
	int count = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> text;
		stack<char> s;

		for (int j = 0; j < text.size(); j++) {
			if (s.empty() || s.top() != text[j]) {
				s.push(text[j]);
			}
			else {
				s.pop();
			}
		}

		if (s.empty()) {
			count++;
		}
	}

	cout << count;
}
