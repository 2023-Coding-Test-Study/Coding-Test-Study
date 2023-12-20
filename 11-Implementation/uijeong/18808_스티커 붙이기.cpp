#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int N, M, K;
int board[40][40];
vector<pair<int,int>> sticker;
int sti[10][10];
int R, C; // 스티커의 사이즈 

void rot() {
    // 회전시키기 
    int tmp[10][10];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            tmp[i][j] = sti[i][j];
        }
    }

    fill(sti[0], sti[9], 0);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            sti[i][j] = tmp[R-1-j][i]; // 수정한 부분 
            if (sti[i][j] == 1) sticker.push_back({ i, j });
        }
    }
    swap(R, C);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) { // 각 스티커에 대해서 
        cin >> R >> C;
        for (int r = 0; r < R; r++) { // 입력 받기 
            for (int c = 0; c < C; c++) {
                cin >> sti[r][c];
                if (sti[r][c] == 1) sticker.push_back({ r, c });
            }
        }


        int r = 0;
        while (r < 4) {
            int sx = 0, sy = 0;
            bool s = true;
            for(int l = 0; l < N; l++){
                for (int k = 0; k < M; k++) {   
                     bool s = true; // 수정한 부분 
                     sx = l; sy = k;
                     for (int i = 0; i < sticker.size(); i++) {
                         int nx = sticker[i].X + l;
                         int ny = sticker[i].Y + k;

                         if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                             s = false;
                             break;
                         }
                         if (board[nx][ny] == 1 && sti[sticker[i].X][sticker[i].Y] == 1) { // 수정한 부분 
                             // 스티커를 놓을 수 없다면 
                             s = false;
                             break;
                         }
                     }

                     if (s) {
                         // 스티커를 놓을 수 있다면
                         for (int i = 0; i < sticker.size(); i++) {
                             int nx = sticker[i].X + sx;
                             int ny = sticker[i].Y + sy;

                             board[nx][ny] = 1;
                         }
                         goto STOP; // 다른 스티커 가져옴 
                     }
                }
            }
            sticker.clear(); // 초기화 
            rot(); // 회전 
            r++;
        }

    STOP:
        sticker.clear();
        fill(sti[0], sti[9], 0);
        
    }

    // count
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) ans++;
        }
    }

    cout << ans;

    return 0;
}
