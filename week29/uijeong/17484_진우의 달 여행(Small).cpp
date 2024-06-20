#include <bits/stdc++.h>

using namespace std;

int N, M; // 행, 열
int board[6][6];
int sum = 0;
int min_s = 1e9;
int d[3] = { -1, 0, 1 }; // 방향

void dfs(int x, int y, int idx) { // 현재 x, y, 이전 방향
    if(x == N-1){
        min_s = min(min_s, sum);
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        int ny = d[i] + y;

        if (ny < 0 || ny >= M || i == idx ) continue; 
        sum += board[x+1][ny];
        dfs(x+1, ny, i);
        sum -= board[x + 1][ny];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    } // input

    for (int i = 0; i < M; i++) {
        sum = board[0][i];
        dfs(0, i, -1);
        
    }

    cout << min_s;
}
