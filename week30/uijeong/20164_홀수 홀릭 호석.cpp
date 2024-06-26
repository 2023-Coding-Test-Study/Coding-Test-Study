#include <bits/stdc++.h>

using namespace std;

int max_ans = -1;
int min_ans = 1e9;

int odd_count(int n) {
	int count = 0;
	while (n > 0) {
		int num = n % 10; // 각 자리 수 digit 추출 
		if (num % 2 == 1) count++; // 홀수 개수
		n /= 10;
	}
	return count;
}
void rec(int n, int odd) {
	if (n < 10) { // 한 자리 수 
		max_ans = max(odd, max_ans);
		min_ans = min(odd, min_ans);
		return;
	}
	else if (n < 100) { //두 자리 수
		int num = n / 10 + n % 10; // 각 자리 수 합 
		rec(num, odd + odd_count(num));
	}
	else { // 세 자리 수 
		string s = to_string(n);
		int s_size = s.size();
		for (int i = 1; i < s_size - 1; i++) { // 분할 할 수 있는 모든 경우 다 계산
			for (int j = i + 1; j < s_size; j++) {
				string s1 = s.substr(0, i);
				string s2 = s.substr(i, j - i);
				string s3 = s.substr(j, s_size - j);
				int news = stoi(s1) + stoi(s2) + stoi(s3);
				rec(news, odd + odd_count(news));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	rec(N, odd_count(N));

	cout << min_ans << " " << max_ans << "\n";
}
