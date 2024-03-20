#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int total = 0;
int board[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int d_idx = 1;
queue<pair<int, char>> q;
int curX = 1;
int curY = 1;
int tailX = 1;
int tailY = 1;
int tail_idx = 1;

struct TurningPoint {
    int x;
    int y;
    int dir;
};

queue<TurningPoint> direction;

void turnDirection(char dir)
{
    if (dir == 'L')
    {
        d_idx += 1;
        if (d_idx >= 4) d_idx -= 4;
    }
    else if (dir == 'D')
    {
        d_idx -= 1;

        if (d_idx < 0) d_idx += 4;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int x, y;

        cin >> x >> y;

        board[x][y] = 1;
    }

    int L;
    cin >> L;

    for (int i = 0; i < L; i++)
    {
        int cnt;
        char dir;
        cin >> cnt >> dir;

        q.push({ cnt , dir });
    }

    board[1][1] = 2;
    int time = 0;
    while (curX <= N && curX >= 1 && curY <= N && curY >= 1)
    {
        if (time >= 1)
        {
            //위치 전환
            if (!q.empty())
            {
                auto item = q.front();

                if (time == item.first)
                {
                    turnDirection(item.second);

                    TurningPoint tmp = { curX, curY, d_idx };
                    direction.push(tmp);
                    q.pop();
                }
            }

            //이동 후 처리
            if (board[curX][curY] == 0)
            {
                board[tailX][tailY] = 0;

                tailX += dx[tail_idx];
                tailY += dy[tail_idx];

                if (!direction.empty())
                {
                    auto item = direction.front();

                    if (tailX == item.x && tailY == item.y)
                    {
                        tail_idx = item.dir;

                        direction.pop();
                    }
                }

            }

            board[curX][curY] = 2;

        }

        time++;

        curX += dx[d_idx];
        curY += dy[d_idx];

        if (board[curX][curY] == 2) break;
    }

    cout << time;
}