#include <bits/stdc++.h>

using namespace std;

int N;
int result = 0;
bool s1[16]; // 주어진 퀸 열
bool s2[40]; // 대각선 오른쪽
bool s3[40]; // 대각선 왼쪽

void attack(int row) {  
	if (row == N) { // N까지 도달했다면
		result++;
		return;
	}

	for (int i = 0; i < N; i++) { // 경우의 수 N열
		if (s1[i] || s2[row+i] || s3[row-i+N-1]) continue; // 셋 중에 하나라도 공격가능하면 넘기기

		s1[i] = true; // 해당 열 배치 
		s2[row + i] = true; // 대각선 체크
		s3[row - i + N - 1] = true; // 대각선 체크 
		attack(row + 1);
		s1[i] = false; // 백 트래킹
		s2[row + i] = false;
		s3[row - i + N - 1] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	attack(0);
	cout << result;
}
