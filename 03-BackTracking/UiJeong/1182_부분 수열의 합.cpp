#include <bits/stdc++.h>

using namespace std;

int n[21];
int N, S;
int ans = 0;

void sumN(int cnt, int sum) { // 현재 더한 횟수, 현재까지의 합 
	if (cnt == N) { 
		if (sum == S) ans++; // S와 동일하면 return
		return;
	}

	sumN(cnt + 1, sum); // 현재 원소 제외
	sumN(cnt + 1, sum + n[cnt]); // 이전 경우를 되돌아서 더한 것과 같음
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	sumN(0, 0);

	if (S == 0) ans--; // 공집합은 반드시 부분 집합에 존재하므로 

	cout << ans;

}
