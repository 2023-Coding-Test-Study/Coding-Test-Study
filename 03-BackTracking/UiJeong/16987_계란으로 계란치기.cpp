#include <bits/stdc++.h>

using namespace std;

int N;
int egg[8][2]; // 내구도와 무게
int c = 0;
int Max = 0;

void hit(int cnt) {
	if (cnt > N) { // 마지막 계란도 반드시 거치고 간다. 
		return;
	}

	for (int i = 0; i < N; i++) {
		if (egg[cnt][0] < 0) hit(cnt + 1); // 손에 든게 깨진거라면 
		else if (egg[cnt][0] > 0 && egg[i][0] > 0 && cnt != i) { // 깨지지 않고 자기자신이 아니라면 
			egg[cnt][0] -= egg[i][1]; // 깨트림
			egg[i][0] -= egg[cnt][1]; // 깨트림 

			hit(cnt + 1); 

			egg[cnt][0] += egg[i][1]; // 이전 상태로 복구 
			egg[i][0] += egg[cnt][1]; 
		}
	}

	int temp = 0;
	for (int i = 0; i < N; i++) {
		if (egg[i][0] <= 0) {
			temp++;
		}
	}
	Max = max(temp, Max);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> egg[i][0] >> egg[i][1];
	}

	hit(0);

	cout << Max;
}
