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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오름차순으로

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
            if (board[i][j] == 9) { // 아기 상어 위치 받기 
                q.push({ i,j });
                dist[i][j] = 0;
                board[i][j] = 0; // 아기 상어 위치 초기화 
            }
        }
    }

    int eat = 2; // 먹어야 하는 횟수 
    int dist_c = 0x3f3f3f3f; // 구한 최단 거리 
    while (!q.empty() || !pq.empty()) {
        if (q.empty()) { // 즉 도착 지점까지 다 도달한 경우 
            pair<int, int> c = pq.top(); // 제일 첫 번째 원소
            t += dist[c.X][c.Y]; // 총 거리 더해주기 
            board[c.X][c.Y] = 0; // 먹음
            // 초기화 
            fill(dist[0], dist[N], -1);
            q.push({ c.X, c.Y });
            dist[c.X][c.Y] = 0;
            dist_c = 0x3f3f3f3f;
            while (!pq.empty()) pq.pop();
            // 먹은 것 처리
            eat--;
            if (eat == 0) {
                sharkS++;
                eat = sharkS;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오름차순으로
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 주어진 보드 범위가 아닌 경우
            if (board[nx][ny] > sharkS) continue; // 큰 물고기인 경우 
            if (dist[nx][ny] != -1) continue; // 이미 방문한 경우 

            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 거리 업데이트 후 
            if (dist[nx][ny] <= dist_c) { // 최단 거리보다 작은 좌표에 대해서 
                if (board[nx][ny] < sharkS && board[nx][ny] > 0) {
                    // 먹어도 되는 경우면
                    if (dist[nx][ny] < dist_c) {// 최단거리보다 작다면
                        dist_c = dist[nx][ny];
                    }
                    // 최단 거리와 같다면
                    pq.push({ nx, ny });
                    continue;
                }
                q.push({ nx, ny });
            }
        }
    }

    cout << t;

}
