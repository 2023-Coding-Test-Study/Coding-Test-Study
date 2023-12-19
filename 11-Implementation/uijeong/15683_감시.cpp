#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[9][9] = { 0, };
int N, M;
int min_width = 1e9;
int dx[4] = { 0, -1, 0, 1 }; // 우 상 좌 하 -> 이게 key point 
int dy[4] = { 1, 0, -1, 0 };

vector<tuple<int, int, int>> cctv;

void check(int x, int y, int dir) { // 해당 방향으로 체크하는 함수 
    dir %= 4; // 방향 정하기
    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
        if (board[nx][ny] == 6) return;
        if (board[nx][ny] != 0) continue; // 이미 방문했을 수도 있음
        board[nx][ny] = -1;
    }
}

void search(int cnt) { // 현재 선택한 cctv
    if (cnt == cctv.size()) {
        int temp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) temp++;
            }
        }

        min_width = min(temp, min_width);
        return;
    }

    int c, x, y; // 번호 좌표
    tie(c, x, y) = cctv[cnt];
    int tmp[9][9]; // 초기화 시켜줄 임시 배열 
    for (int dir = 0; dir < 4; dir++) { // 결국 90도 회전 시 4방향을 모두 확인해야 함
        for (int i = 0; i < N; i++) // 현재 상태 저장 
            for (int j = 0; j < M; j++)
                tmp[i][j] = board[i][j];

        if (c == 1)
            check(x, y, dir);
        else if (c == 2) {
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (c == 3) {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (c == 4) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        else if (c == 5) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        search(cnt + 1);
        // 초기화 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                board[i][j] = tmp[i][j];
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] < 6 && board[i][j] > 0) {
                cctv.push_back({ board[i][j], i,j }); // cctv 번호, 좌표
            }
        }
    }
    
    search(0);
    cout << min_width;
   
    return 0;
}
