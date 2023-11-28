#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int board[21][21]; // 좌표 공간 
int dist[21][21]; // 좌표 공간 
int dx[4] = { -1,0, 1, 0 }; // 위 왼쪽 순으로 탐색한다. (중요)
int dy[4] = { 0,-1,0,1 };
int sharkS = 2; // 아기상어 사이즈
int t = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
            if (board[i][j] == 9) { // 아기 상어 위치 받기 
                q.push({ i,j });
                dist[i][j] = 0;
            }
        }
    }

    int eat = 2; // 먹어야 하는 횟수 
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 주어진 보드 범위가 아닌 경우
            if (board[nx][ny] > sharkS) continue; // 큰 물고기인 경우 
            if (dist[nx][ny] != -1) continue; // 이미 방문한 경우 

            q.push({ nx, ny });
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;

            if (board[nx][ny] < sharkS && board[nx][ny] > 0) {
                // 먹어도 되는 경우면
                t += dist[cur.X][cur.Y] + 1; // 이동 시간 추가
                board[nx][ny] = 0; // 빈칸으로 바꿈 
                while (!q.empty()) q.pop(); // 큐 비우기 
                q.push({ nx, ny }); // 시작점 추가 
                fill(dist[0], dist[N], -1); // 거리 초기화 
                eat--;
                if (eat == 0) {
                    sharkS++;
                    eat = sharkS;
                }
            }
        }
    }

    cout << t;
    
}
