#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[110][110];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2; // 좌표가 겹치면 안 되므로
    
    for(int i = 0; i < 110; i++){
        fill(board[i], board[i]+110, -1);
    }
    
    for(int i=0; i < rectangle.size(); i++){ // 직사각형 색칠 
       for(int x = rectangle[i][0]*2; x <= rectangle[i][2]*2; x++){ 
            for(int y=rectangle[i][1]*2; y <= rectangle[i][3]*2; y++) board[x][y]= 0; // 직사각형 경로 
        }
    }
    
    for(int i=0; i < rectangle.size(); i++){ // 직사각형 내부 제거 == 바깥 부분만 남게 된다. 
       for(int x = rectangle[i][0]*2+1; x <= rectangle[i][2]*2-1; x++){  
            for(int y=rectangle[i][1]*2+1; y <= rectangle[i][3]*2-1; y++) board[x][y]= -1; // 직사각형 경로 
        }
    }
    
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.Y == itemY && cur.X == itemX) // 만약 아이템에 도착했다면 
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (board[nx][ny] == 0) // 경로인 것에 대해서
            {
                q.push({nx,ny});
                board[nx][ny] = board[cur.X][cur.Y] + 1;
            }
        }
    }
    
    answer = board[itemX][itemY] / 2; // 좌표를 모두 2배 늘렸으므로 
    
    return answer;
}
