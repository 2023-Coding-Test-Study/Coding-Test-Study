#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[21][21][2];
vector<pair<int, int>> v; // 좌표
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct c {
    int x1, y1;
    int x2, y2;
};

int bfs() {
    queue<c> q;
    q.push({ v[0].first, v[0].second, v[1].first, v[1].second });

    while (!q.empty()) {
        c cur = q.front(); q.pop();
        int x1 = cur.x1;
        int y1 = cur.y1;
        int x2 = cur.x2;
        int y2 = cur.y2;

        for (int i = 0; i < 4; i++) {
            int nx1 = cur.x1 + dx[i]; int ny1 = cur.y1 + dy[i];
            int nx2 = cur.x2 + dx[i]; int ny2 = cur.y2 + dy[i];

            if (board[nx1][ny1][0] == -1 && board[nx2][ny2][1] == -1) continue; // 둘 다 벽인 경우 넘어가기 

            // 각각 탈출에 대한 경우의 수에 대해 판단 
            if ((nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M) && (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= M)) continue; // 둘다 바깥인 경우
            if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M) {
                // coin1 탈출 
                if (board[x1][y1][0]+1 > 10) return -1; // 10번 넘은 경우 탈출 
                else return board[x1][y1][0]+1;
            }
            if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= M) {
                // coin2 탈출 
                if (board[x2][y2][1]+1 > 10) return -1; // 10번 넘은 경우 탈출 
                else return board[x1][y1][1]+1;
            }
            
            // 각각의 벽에 부딪힌 경우의 수에 대해 판단
            if (board[nx1][ny1][0] == -1) nx1 -= dx[i], ny1 -= dy[i]; // coin1만 벽인 경우 coin1만이동 ㄴㄴ
            if (board[nx2][ny2][1] == -1) nx2 -= dx[i], ny2 -= dy[i]; // coin2만 벽인 경우 coin2만 이동 ㄴㄴ

            // 둘 중에 하나라도 방문하지 않았을 때
            if (board[nx1][ny1][0] == 0 || board[nx2][ny2] == 0) {
                q.push({ nx1, ny1, nx2, ny2 });
            }
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 1. 보드 표시 
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'o') {
                v.push_back({ i, j });
            } // 동전인 경우
            if (s[j] == '#') {
                board[i][j][0] = -1; // 벽인 경우 
                board[i][j][1] = -1;
            }  
        }
    }

    // 2. bfs로 너비 탐색 후 결과 
    cout << bfs();
}
