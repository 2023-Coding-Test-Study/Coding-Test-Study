#include <bits/stdc++.h>
using namespace std;

string c[65];
string answer = "";

bool check(int x1, int y1,int s) {
	for (int i = x1; i < x1+s; i++) {
		for (int j = y1; j < y1+s; j++) {
			if (c[x1][y1] != c[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void div(int x1, int y1, int s) {

	if (check(x1, y1, s)) { // 같다면
		cout << c[x1][y1]; // 해당 값 출력
	}
	else { // 같지않다면
		int n_s = s / 2;
		cout << "(";
		div(x1, y1, n_s); // 1번
		div(x1, y1+n_s, n_s); // 2번
		div(x1+n_s, y1, n_s); // 3번
		div(x1+n_s, y1+n_s, n_s); // 4번
		cout << ")";
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> c[i]; // 문자열 input 저장 
	}

	div(0, 0, N);
}
