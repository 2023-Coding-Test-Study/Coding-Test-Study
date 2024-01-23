#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[51][51];
int temp[51][51];
int c = 0; // 미세먼지 기계 첫번째 행 
int N, M, T;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dust() { // 미세먼지 확산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] == -1) { // 공기청정기인 경우 
                temp[i][j] = -1;
            }

            if (board[i][j] > 0) {
                // 미세먼지가 존재한다면 
                int count = 0;
                vector<pair<int, int>> t; // 임시저장 용
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
                    if (board[i][j] == -1) continue; // 공기청정기인 경우 
                    count++;
                    t.push_back({ nx, ny });
                }
                // 미세먼지 확산 부분
                int d = (int)(board[i][j] / 5)*count;
                temp[i][j] = board[i][j] - d;
                for (auto cur : t) {
                    temp[cur.X][cur.Y] = d;
                }
            }
        }
    }

    // 복붙 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] == -1) continue;
            board[i][j] = temp[i][j];
            temp[i][j] = 0; // 초기화 
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1 && c == 0) {
                // 위쪽 공기청정기 발견 시 
                c = i;
            }
        }
    }

    while (T > 0) {
        dust(); // 확산 -> 보드 업데이트 

        // 왼 -> 오
        for (int j = 2; j <= M-1; j++) {
            temp[c][j+1] = board[c][j]; // 위쪽
            temp[c+1][j + 1] = board[c+1][j]; // 아래쪽
        }
        // 아 -> 위
        for (int i = c; i >= 2; i--) {
            temp[i - 1][M] = board[i][M];
        }
        // 위 -> 아 (아래)
        for (int i = c + 1; i <= N - 1; i++) { 
            temp[i + 1][M] = board[i][M];
        }
        
        // 오 -> 왼
        for (int j = M; j >= 2; j--) {
            temp[1][j-1] = board[1][j]; // 위쪽
            temp[N][j + 1] = board[N][j]; // 아래쪽
        }

        // 위 -> 아
        for (int i = 1; i <= c-1; i++) {
            temp[i+1][1] = board[i][1];
        }
        // 아 -> 위
        for (int i = N; i >= c+2; i--) { // 아래쪽
            temp[i - 1][1] = board[i][1];
        }

        // 복붙 
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (board[i][j] == -1) continue;
                board[i][j] = temp[i][j];
                temp[i][j] = 0; // 초기화 
            }
        }

    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] == -1) continue;
            sum += board[i][j];
        }
    }
    cout << sum;
}
