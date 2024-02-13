#include <bits/stdc++.h>
using namespace std;

int board[100][100];
bool vis[100][100];
int N;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int minH = 1e9;
int maxH = 0;
int ans = 0;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vis[i][j] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            minH = min(minH, board[i][j]);
            maxH = max(maxH, board[i][j]);
        }
    } // 입력 

    int count = 0;
    while (count <= maxH) {
        int temp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] > count && vis[i][j] == false) { // 안전지대 발견시 영역 찾기 
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    vis[i][j] = true;
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        
                        for (int i = 0; i < 4; i++) {
                            int nx = cur.first + dx[i];
                            int ny = cur.second + dy[i];

                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (board[nx][ny] <= count || vis[nx][ny] == true) continue;
                            q.push({ nx, ny });
                            vis[nx][ny] = true;
                        }
                    }
                    temp++; // 영역 개수 count

                }
            }
        }

        ans = max(ans, temp);
        count++;
        init();
    }
    cout << ans;
}
