#include<bits/stdc++.h>

using namespace std;

int T, N, M;
long long K; // 최대 10억
int house[100000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		int answer = 0; // 답
		cin >> N >> M >> K;
		for (int j = 0; j < N; j++) {
			cin >> house[j];
		} // 입력 

		int left = 0;
		int right = left + M -1; // 투 포인터 초기화 
		long long sum = 0;
		for (int k = left; k <= right; k++) sum += house[k]; // 합산 

		while (true) {
			if (sum < K) answer++;
			if (right - left == N - 1) break; // 차이가 1만 나는 경우 종료

			left++, right++;
			if (left == N) break; // 종료조건 
			if (right == N) right = 0;
			sum -= house[left - 1]; // 이전의 left 제거
			sum += house[right]; // 현재 right 추가
		}

		cout << answer << "\n";
	}
}
