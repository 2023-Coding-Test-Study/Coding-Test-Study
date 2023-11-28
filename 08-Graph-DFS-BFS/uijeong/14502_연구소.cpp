#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[9][9];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0,1,0,-1 };
int N, M;
int max_c = 0;

void bfs() {
    queue<pair<int, int>> q; // 좌표 저장 
    int testB[9][9]; // 테스트할 임시 보드 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            testB[i][j] = board[i][j]; // 현재 보드 복붙
            if (board[i][j] == 2) {
                q.push({ i,j });
            }
        }
    } // 바이러스 저장

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (testB[nx][ny] != 0) continue; // 이미 방문 or 벽

            testB[nx][ny] = 2; // 전염됨
            q.push({ nx,ny }); // 추가 
        }
    }

    // 오염되지 않은 부분 체크
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (testB[i][j] == 0) {
                // 전염 안 됨 
                count++;
            }
        }
    }
    max_c = max(max_c, count);
}

void selectWall(int cur) {
    if (cur == 3) {
        bfs(); // 너비 측정
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1; // 벽 세움
                selectWall(cur + 1); 
                board[i][j] = 0; // 원상복구
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 3개 선택후 bfs
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                // 빈칸 발견 
                board[i][j] = 1; // 벽 세우기 
                selectWall(1); // 벽 3개 선택 
                board[i][j] = 0; // 초기화 
            }
        }
    }

    cout << max_c;
}
