#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[101][101] = { 0, };
int N, K, D;
queue<pair<int, char>> path;
pair<int, char> cur; // 변경할 다음 변수 
pair<int, int> direct = { 0, 1 }; // 방향을 의미
deque<pair<int, int>> snake;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1; // 사과 존재
    }
    cin >> D;
    for (int i = 0; i < D; i++) {
        int t;
        char c;
        cin >> t >> c;
        path.push({ t, c }); // 경로 저장 
    }

    board[1][1] = 2;
    snake.push_front({ 1,1 });
    int time = 0; // 최종 시간
    pair<int, int> head;
    while (true) { // 1초 동안 보드를 업데이트 및 순회 
        time++; // 시간 증가 
        cur = path.front();
        head = snake.front();
        bool apple = false; // 사과 칸 체크 
        
        head.X += direct.X;
        head.Y += direct.Y;

        // 뱀 머리 이동 
        snake.push_front({ head.X, head.Y});
        
        // 뱀이 벽에 부딪히는지 or 몸통과 부딪히는지 or 사과인지 체크
        if (head.X < 1 || head.X > N || head.Y < 1 || head.Y > N) {
            cout << time;
            return 0;
        }
        if (board[head.X][head.Y] == 2) {
            // 뱀의 위치라면
            cout << time;
            return 0;
        }

        if(board[head.X][head.Y] == 1) {
            // 사과라면
            board[head.X][head.Y] = 0; // 기본으로 
            apple = true;
        }
       

        if (!apple) { // 사과가 아닌 경우 
            pair<int, int> b = snake.back();
            snake.pop_back();
            board[b.X][b.Y] = 0;
        }

        // 헤드 업데이트 
        board[head.X][head.Y] = 2;

        if (cur.first == time) { // 해당 시간이 갖다면 
            int a = direct.first;
            int b = direct.second;
            if (cur.second == 'L') { // 왼쪽
                direct = { -b, a };
            }
            else { // 오른쪽
                direct = { b, a };
            }
        } 
        apple = false;
    }
   
    return 0;
}
