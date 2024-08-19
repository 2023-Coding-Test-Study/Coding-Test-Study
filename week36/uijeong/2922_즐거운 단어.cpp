#include <bits/stdc++.h>

using namespace std;

long long ans;
string word;
bool happy_word[101];
vector<int> pos; // 밑줄 위치 파악
int s = 0;
int ct = 0;
bool exist = false; // L이 존재하는 지 

bool check() { // 연속된 3개의 모음 자음 존재 체크
	int sum = happy_word[0] + happy_word[1]+ happy_word[2];
	for (int i = 3; i < s; i++) {
		sum -= happy_word[i-3]; // 이전 값 제거
		sum += happy_word[i]; // 현재 값 추가
		if (sum == 0 || sum == 3) return false; // 모음 또는 자음 모음집
	}
	return true;
}

void dfs(int cnt) {
	if (cnt > ct) {
		if (check()) { // true인 경우 
			int X = 0; // 자음
			int O = 0; // 모음
			int mul = 1; // 경우의 수 
			for (int i = 0; i < ct; i++) { // 각 인덱스에 대해서 
				if (happy_word[i]) { // 모음인 경우
					O++;
					mul *= 5;
				}
				else {
					X++;
					mul *= 21;
				}
			}
			
			if (!exist && X == 0) { // L이 존재하지 않고 자음이 없는 경우
				return; // 불가능 
			}
			if (!exist) {
				// L이 존재하지 않는 경우 
				if (O == 0) {
					// 모음이 존재 하지 않을 때 
					mul = pow(21, X) - pow(20, X); // 즉 전체 경우의 수 - L만 제외한 경우의 수 
				}
				else {
					// 모음도 존재하는 경우
					mul = (pow(21, X) - pow(20, X)) * pow(5, O);
				}
			}
			ans += mul;
			
		}

		return;
	} // 단어 끝까지 도달한 경우

	int j = pos[cnt];
	for (int i = 0; i < 2; i++) { // 0이면 자음 1이면 모음
		happy_word[j] = i;
		dfs(cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> word;
	s = word.size();
	for (int i = 0; i < s; i++) {
		if (word[i] == '_') {
			pos.push_back(i);
			ct++;
		} 
		if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') happy_word[i] = 1;
		if (word[i] == 'L') exist = true;
	} // 밑 줄 파악 

	dfs(0);
}
