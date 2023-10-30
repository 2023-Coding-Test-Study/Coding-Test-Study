#include <bits/stdc++.h>
using namespace std;

int N;
char star[2200][2200];

void fill(int x, int y, int s, char c) { // 시작점, 정사각형 크기, 들어갈 문자
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (i == 1 && j == 1) star[x + i][y + j] = ' ';
			else star[x + i][y + j] = c;
		}
	}
}

void div(int x, int y, int s) {
	if (s == 3) { // 종료 조건
		fill(x, y, s, '*');
		return;
	}

	int n_s = s / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) fill(x + n_s * i, y + n_s * j, n_s, ' '); // 가운데인 경우 빈칸 채우기
			else div(x+n_s*i, y + n_s * j, n_s); // 아닌 경우 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	div(0,0,N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}
}
