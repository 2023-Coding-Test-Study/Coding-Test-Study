#include <bits/stdc++.h>
using namespace std;

int N[9][9], L;
vector<pair<int, int> > v;

bool isEnd = false;

bool check(int x, int y, int value) { // 해당 value가 들어가도 되는지 확인
	for (int i = 0; i < 9; i++) {
		if (N[i][y] == value) return false;
		if (N[x][i] == value) return false;
	}
	
	// 정사각형
	int s_x = x / 3;
	int s_y = y / 3;
	s_x *= 3;
	s_y *= 3;
	for (int i = s_x; i < s_x + 3; i++) {
		for (int j = s_y; j < s_y + 3; j++) {
			if (N[i][j] == value) return false;
		}
	}
	return true;
}

void dfs(int cur) {
	if (isEnd == true) return;
	if (cur == L) { // 81번째인 경우 
		for (int i = 0; i < 9; i++) { // 출력 
			for (int j = 0; j < 9; j++) {
				cout << N[i][j] << ' ';
			}
			cout << '\n';
		}
		isEnd = true;
	}
	else {
		int nx = v[cur].first;
		int ny = v[cur].second;
		for (int i = 1; i <= 9; i++) {
			if (check(nx, ny, i)) {
				N[nx][ny] = i;
				dfs(cur + 1);
				// 백트래킹
				N[nx][ny] = 0;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> N[i][j];
			if (N[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	L = v.size();
	dfs(0);
}
