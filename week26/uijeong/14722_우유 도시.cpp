#include <vector>
#include <iostream>
using namespace std;

int d[1000][1000][3];
int N;
int board[1000][1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	} // 입력 저장 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int currentMilk = board[i][j]; // 현재 우유 

			/* (i, j)에 대해서 딸기 우유 처리 */
			if (currentMilk == 0) {
				d[i][j][0] = max(d[i][j - 1][2], d[i - 1][j][2]) + 1;
				// 인접한 경우의 가장 최근에 바나나 마신 개수 
			}
			else { // current가 딸기가 아닌 경우 이전의 최댓값 이어감 
				d[i][j][0] = max(d[i][j - 1][0], d[i - 1][j][0]);
			}

			if (currentMilk == 1 && d[i][j][0] > d[i][j][1]) { // 초코인데 바로 전에 초코를 마셨는지 확인 
				d[i][j][1] = max(d[i][j - 1][0], d[i - 1][j][0]) + 1;
			}
			else {
				d[i][j][1] = max(d[i][j - 1][1], d[i - 1][j][1]);
			}

			if (currentMilk == 2 && d[i][j][1] > d[i][j][2]) {
				d[i][j][2] = max(d[i][j - 1][1], d[i - 1][j][1]) + 1;
			}
			else {
				d[i][j][2] = max(d[i][j - 1][2], d[i - 1][j][2]);
			}
		}
	}

	cout << max(d[N - 1][N - 1][0], max(d[N - 1][N - 1][1], d[N - 1][N - 1][2]));

	return 0;

}
