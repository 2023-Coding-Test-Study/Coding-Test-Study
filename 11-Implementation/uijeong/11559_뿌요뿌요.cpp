#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

string board[12];
bool visited[12][12] = { false, }; // 방문 여부 
vector<pair<int, int>> bomb; // 터트릴 뿌요 좌표들 
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q; // 방문을 위한 좌표 
int answer = 0;

vector<pair<int, int>> dfs(int x, int y) { // 현재 좌표 색깔에 맞는 인접한 뿌요 count
    vector<pair<int, int>> temp;
    q.push({ x, y });
    visited[x][y] = true; // 방문 표시 
    temp.push_back({ x, y });

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (visited[nx][ny] == true || board[nx][ny] != board[x][y]) continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
            temp.push_back({ nx, ny });
        }
    }

    return temp;
}

void gravity(int j) {
    queue<char> tmp;
    for (int i = 11; i >= 0; i--) {
        if (board[i][j] != '.') {
            tmp.push({ board[i][j] });
            board[i][j] = '.';
        }
    }

    int idx = 11;
    while (!tmp.empty()) {
        board[idx][j] = tmp.front();
        tmp.pop();
        idx--;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        cin >> board[i];
    }

    while (true) {
        // 뿌요 탐색 
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                vector<pair<int, int>> t;
                if (board[i][j] != '.') {
                    // 빈공간이 아니라면 방문! 
                    t = dfs(i, j);
                    if (t.size() >= 4) { // 탐색한 뿌요 크기가 4 이상인 경우 
                        bomb.insert(bomb.end(), t.begin(), t.end()); // 추가 
                    }
                }
            }
        }

        if (!bomb.empty()) {
            // 해당 뿌요 모두 제거 
            for (int i = 0; i < bomb.size(); i++) {
                pair<int, int> cur = bomb[i];
                board[cur.X][cur.Y] = '.'; // 모두 빈칸 
            }
            bomb.clear();
            fill(visited[0], visited[12], false);

            // 중력 작용
            for (int j = 0; j < 6; j++) gravity(j);
            answer++;
        }
        else break;
        
    }

    cout << answer;

    return 0;
}
