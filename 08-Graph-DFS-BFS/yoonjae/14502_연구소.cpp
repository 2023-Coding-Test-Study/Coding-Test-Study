#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[9][9];
int N, M;
int wallBoard[9][9];
vector<pair<int, int>> v;


int CheckSafetyZone()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (wallBoard[i][j] == 0)
            {
                cnt++;
            }

        }
    }

    return cnt;
}


int bfs()
{
    for (auto& item : v)
    {
        queue<int> q;
        q.push((item.first * M + item.second));

        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();

            int dirX[] = { 1, 0, -1, 0 };
            int dirY[] = { 0, -1, 0, 1 };

            for (int i = 0; i < 4; i++)
            {
                int x = (tmp / M) + dirX[i];
                int y = (tmp % M) + dirY[i];

                if (x >= 0 && x < N && y >= 0 && y < M)
                {
                    if (wallBoard[x][y] == 0)
                    {
                        wallBoard[x][y] = 2;
                        q.push((x * M) + y);
                    }
                }
            }
        }
    }
    int res = CheckSafetyZone();

    return res;
}

void ResetWallBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            wallBoard[i][j] = board[i][j];
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp;

            board[i][j] = tmp;

            if (tmp == 2) v.push_back(make_pair(i, j));
        }
    }

    int max = -1;
    int size = N * M;
    for (int i = 0; i < size - 2; i++)
    {
        int x1, y1;
        x1 = i / M;
        y1 = i % M;

        if (board[x1][y1] == 2 || board[x1][y1] == 1) continue;

        for (int j = i + 1; j < size - 1; j++)
        {
            int x2, y2;
            x2 = j / M;
            y2 = j % M;

            if (board[x2][y2] == 2 || board[x2][y2] == 1) continue;

            for (int k = j + 1; k < size; k++)
            {
                int x3, y3;
                x3 = k / M;
                y3 = k % M;

                if (board[x3][y3] == 2 || board[x3][y3] == 1) continue;

                ResetWallBoard();

                wallBoard[x1][y1] = 1;
                wallBoard[x2][y2] = 1;
                wallBoard[x3][y3] = 1;

                int ans = bfs();

                if (ans > max) max = ans;
            }
        }
    }

    cout << max;

}
