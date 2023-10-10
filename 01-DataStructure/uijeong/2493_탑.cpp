#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	stack<int> s; // 순서 
	int h[5000001]; // 높이

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> h[i];

		while(!s.empty() && h[s.top()-1] < h[i]){
			// 비어있는 경우 체크하면 error 발생
			s.pop();
		}

		if (s.empty()) {
			// 레이저 닿는 애가 없으면
			cout << 0 << " ";
		}
		else {
			// 닿는 애가 있다.
			cout << s.top() << " ";
		}

		s.push(i+1); // 가장 먼저 확인하는 것은 내 앞의 번호이기 때문 
	}

}
