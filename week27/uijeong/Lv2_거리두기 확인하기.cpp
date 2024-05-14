#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5, 1);
    queue<pair<int, int>> q;

    for (int n = 0; n < 5; n++) {
            for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (places[n][i][j] == 'P') {
                            int vis[5][5];
                            fill(&vis[0][0], &vis[5][5], -1);
                            q.push({ i, j });
                            vis[i][j] = 0;
                            while (!q.empty()) {
                                auto cur = q.front(); q.pop();
                                for (int k = 0; k < 4; k++) {
                                    int nx = cur.first + dx[k];
                                    int ny = cur.second + dy[k];

                                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                                    if (vis[nx][ny] != -1 || places[n][nx][ny] == 'X') continue;

                                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                                    if (places[n][i][j] == 'P') {
                                        if (vis[nx][ny] <= 2) {
                                            // 거리가 2 이하인 경우 
                                            answer[i] = 0; // 하나 이상이 거리두기 지키지 X
                                        }
                                    }
                                    else {
                                        q.push({ nx, ny });
                                    }

                                }
                            }
                        }
                    }
                }
    }
    

    return answer;
}

int main(void) {
    vector<int> a;
    a = solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
    for (int i = 0; i < 5; i++) {
        cout << a[i] << "\n";
    }
}
