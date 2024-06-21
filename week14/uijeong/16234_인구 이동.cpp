#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[51][51];
bool vis[51][51];

vector<pair<int, int>> v; // 연합 팀 
int sum = 0; // 총합 
int N, L, R;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool falg = false; // 연합 여부 

void bfs(int x, int y) { // 연합 탐색 용도 
    stack<pair<int, int>> s;
    s.push({ x, y }); // 시작점
    v.push_back({ x, y }); // 연합 벡터 추가 
    sum = board[x][y]; // 초기 합 
    vis[x][y] = true; // 방문 

    while (!s.empty()) {
        auto cur = s.top(); s.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] == true) continue; // 만약 이미 방문했거나 
            int m = abs(board[cur.X][cur.Y] - board[nx][ny]);
            if (m >= L && m <= R) { // 해당 간격에 해당하는 경우 
                vis[nx][ny] = true;
                s.push({ nx,ny });
                sum += board[nx][ny]; // 연합 합
                v.push_back({ nx,ny });
            }
        }
    }
}

void clear() {
    // 방문 여부 초기화 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vis[i][j] = false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int day = 0;
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    } // 입력 
    
    bool flag = false;
    while (true) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) { 
                if (vis[i][j] == false) { // 방문하지 않았다면 
                    v.clear(); // 탐색 벡터 초기화 
                    bfs(i, j); // 연합 탐색
                }

                if (v.size() >= 2) {
                    // 연합국이 형성 되었다면 
                    flag = true;
                    for (int i = 0; i < v.size(); i++) {
                        board[v[i].first][v[i].second] = (int)(sum / v.size());
                    }
                }
            }
        }
        if (flag) {
            day++;
            flag = false; // 초기화 
            clear(); // 방문 여부 초기화 
        }
        else {
            break; // 연합이 존재하지 않는 경우 
        }
    }
    
    cout << day;
}
