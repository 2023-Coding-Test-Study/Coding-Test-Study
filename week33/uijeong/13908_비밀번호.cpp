#include <bits/stdc++.h>

using namespace std;

int N, M;
int p[7];
int cnt = 0;

void dfs(int idx, string str) { // 현재 숫자 채운 개수, 현재 문자열
	if (idx == N) {
		bool c = true;
		for (int i = 0; i < M; i++) { // 필요한 숫자
			bool temp = false;
			for (int j = 0; j < str.size(); j++) {
				if (str[j] - '0' == p[i]) { // 문자열에 존재하는가?
					temp = true;
					break;
				}
			}
			if (!temp) { // 문자열에 존재하지 않는 경우
				c = false;
				break;
			}
		}
		if (c) {
			cnt++;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		char c = i + '0'; // 숫자를 char로 변환하기 위함
		dfs(idx + 1, str + c);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> p[i];
	} // 입력값 받기

	dfs(0, "");
	cout << cnt;
	return 0;
}
