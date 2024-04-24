#include<bits/stdc++.h>

using namespace std;

int T; // 테스트 케이스 개수 
string cmd; // 명령어 
int a1, b1, a2, b2;
int dx[4] = {0, -1, 0, 1}; // 북 동 남 서
int dy[4] = {-1, 0, 1, 0};

void cal(int x, int y) { 
	a1 = min(a1, x);
	b1 = min(b1, y);
	a2 = max(a2, x);
	b2 = max(b2, y);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> cmd;
		int s = cmd.size();
		int dir = 0; // 방향, 초기에는 북쪽 
		a1 = 0; a2 = 0; b1 = 0; b2 = 0;
		pair<int, int> coor = { 0, 0 }; // 초기 좌표 

		for (int k = 0; k < s; k++) {
			if (cmd[k] == 'L') { // 왼쪽으로 90도
				dir++;
				dir = dir % 4; // 범위 넘어가는 거 대비 
			}
			else if (cmd[k] == 'R') { // 오른쪽으로 90도
				dir--;
				dir = (dir + 4) % 4; // 범위 넘어가는 거 대비 
			}
			else if (cmd[k] == 'F') { // 앞으로 
				coor.first += dx[dir];
				coor.second += dy[dir];
				cal(coor.first, coor.second);
			}
			else if (cmd[k] == 'B') { // 뒤로 
				coor.first -= dx[dir];
				coor.second -= dy[dir];
				cal(coor.first, coor.second);
			}
		}

		cout << (a2 - a1) * (b2 - b1) << "\n";
	}

	return 0;
}
