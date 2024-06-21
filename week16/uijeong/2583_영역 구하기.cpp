#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M, K;
int board[101][101];
int vis[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    // 1. 직사각형 표시 
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = x2 - x1;
        int y = y2 - y1;
        for (int m = x1; m < x; m++) { 
            for (int n = y1; n < y; n++) {
                board[m][n] = 1;
            }
        }
    }

    // 2. bfs로 너비 탐색 
    priority_queue<int, vector<int>, greater<int>> ans;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0) continue;
            if (vis[i][j] == true) continue;
            q.push({ i, j });
            vis[i][j] = true;
            int cnt = 0;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();

                for (int k = 0; k < 4; k++) {
                    int x = cur.X + dx[k];
                    int y = cur.Y + dy[k];

                    if (x < 0 || x >= M || y < 0 || y >= N) continue;
                    if (board[x][y] == 1 || vis[x][y] == true) continue;
                    q.push({ x,y });
                    vis[x][y] = true;
                    cnt++;
                }
            }
            ans.push(cnt);
        }
    }
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.top() << " ";
        ans.pop();
    }
}
