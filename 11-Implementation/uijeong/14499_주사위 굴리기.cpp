#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[20][20] = { 0, };
int N, M, T;
int dice[7] = { 0, };
int temp[7];
pair<int, int> c; // 주사위가 놓인 좌표

void down() { // 남
    copy(dice, dice + 7, temp);
    dice[1] = temp[5];
    dice[2] = temp[1];
    dice[5] = temp[6];
    dice[6] = temp[2];
}

void up() { // 북
    copy(dice, dice + 7, temp);
    dice[1] = temp[2];
    dice[2] = temp[6];
    dice[5] = temp[1];
    dice[6] = temp[5];
}

void left() { // 서 
    copy(dice, dice + 7, temp);
    dice[1] = temp[4];
    dice[3] = temp[1];
    dice[4] = temp[6];
    dice[6] = temp[3];
}

void right() { // 동
    copy(dice, dice + 7, temp); 
    dice[1] = temp[3];
    dice[3] = temp[6];
    dice[4] = temp[1];
    dice[6] = temp[4];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> N >> M >> x >> y >> T;
    c = { x, y };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < T; i++) {
        int task = 0;
        cin >> task;

        if (task == 1) { // 동쪽
            if (c.Y >= M - 1) continue; // 범위 벗어날 경우 
            else {
                c = { c.X, c.Y + 1 };
                right();
            }
        }

        if (task == 2) { // 서쪽
            if (c.Y <= 0) continue; // 범위 벗어날 경우 
            else {
                c = { c.X, c.Y -1 };
                left();
            }
        }

        if (task == 3) { // 북쪽
            if (c.X <= 0) continue; // 범위 벗어날 경우 
            else {
                c = { c.X-1, c.Y};
                up();
            }
        }

        if (task == 4) { // 남쪽 
            if (c.X >= N-1) continue; // 범위 벗어날 경우 
            else {
                c = { c.X+1, c.Y};
                down();
            }
        }

        cout << dice[6] << "\n";

        if (board[c.X][c.Y] == 0) {
            board[c.X][c.Y] = dice[1];
        }
        else {
            dice[1] =  board[c.X][c.Y];
            board[c.X][c.Y] = 0;
        }
    }
   
    return 0;
}
