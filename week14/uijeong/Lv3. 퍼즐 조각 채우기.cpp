#include <bits/stdc++.h>

using namespace std;

int N, answer;
int bdx[4] = {1, 0, -1, 0}; 
int bdy[4] = {0, 1, 0, -1};
int tdx[4] = {0, -1, 0, 1}; 
int tdy[4] = {1, 0, -1, 0};
vector<vector<int>> board, t;

bool check(int tx, int ty, int bx, int by) {
    vector<vector<int>> temp_b = board;
    vector<vector<int>> temp_t = t;

    int cnt = 0;

    queue<vector<int>> q;
    q.push({bx, by, tx, ty}); // 해당 시작점에 대해서 큐 추가
    while(!q.empty()) {
        vector<int> v = q.front();
        q.pop();

        // 범위 밖일 때 
        if(v[0] < 0 || v[0] >= N || v[1] < 0) || v[1] >= N) continue;
        if(v[2] < 0 || v[2] >= N || v[3] < 0) || v[3] >= N) continue;
        
    
        if (temp_b[v[0]][v[1]] == 0) return false; // 현재 칸 
        else continue; // (B, T) = (1, 0) 퍼즐 칸 끼우기 확인X
        
        
        if (temp_t[v[2]][v[3]] == 1) return false; // (B, T) = (1, 1) 퍼즐 칸 끼우기 불가능
        else continue; // (B, T) = (1, 0) 퍼즐 칸 끼우기 확인X
        

        if ((temp_b[v[0]][v[1]] == 1) && (temp_t[v[2]][v[3]] == 0)) continue; // (B, T) = (1, 0) 퍼즐 칸 끼우기 확인X
        if ((temp_b[v[0]][v[1]] == 0) && (temp_t[v[2]][v[3]] == 1)) { // (B, T) = (0, 1) 퍼즐 칸 끼우기 가능
            temp_b[v[0]][v[1]] = 1;
            temp_t[v[2]][v[3]] = 0;
            cnt++;
        }
        else return false; // (B, T) = (0, 0) or (1, 1) 퍼즐 칸 끼우기 불가능

        for(int i=0; i<4; i++) q.push({v[0] + bdx[i], v[1] + bdy[i], v[2] + tdx[i], v[3] + tdy[i]});
    }
    
    answer += cnt; // 퍼즐 한 개 칸 개수
    board = temp_b; // 퍼즐 끼우기
    t = temp_t;
    
    return true;
}

void rotate() { // 시계 방향
    int tempX = tdx[3];
    int tempY = tdy[3];
    for(int i=2; i>=0; i--) { // 뒤에서부터
        tdx[i+1] = tdx[i];
        tdy[i+1] = tdy[i];
    }
    tdx[0] = tempX;
    tdy[0] = tempY;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    N = game_board.size();
    board = game_board; // 주소 할당
    t = table;
    
    // 시작점 선택
    for(int i=0; i< N; i++) { // BFS 
        for(int j=0; j<N; j++) { 
            if (board[i][j] == 0) { // 빈 공간 존재 시 
                for(int a=0; a<N; a++) {
                    for(int b=0; b<N; b++) {
                        if (t[a][b] == 1) { 
                            // 보드 확인(회전 시계 방향 90도, 180도, 270도)
                            rotate(); // 우하좌상
                            if (check(a, b, i, j)) continue;

                            rotate(); // 상우하좌
                            if (check(a, b, i, j)) continue;

                            rotate(); // 좌상우하
                            if (check(a, b, i, j)) continue;

                            rotate(); // 하좌상우
                            if (check(a, b, i, j)) continue;
                        }
                    }
                }
            }
        }
    }

    return answer;
}
