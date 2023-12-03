#include <iostream>
#include <queue>

using namespace std;

int board[1001][1001];
int N, M;
int visited[1001][1001][2];

struct LocInfo
{
    int x;
    int y;
    int dist;
    int cnt;
};

void bfs()
{
    queue<LocInfo> q;
    LocInfo start = { 0,0,1,0 };
    visited[0][0][0] = 1;
    visited[0][0][1] = -1;
    q.push(start);

    while (!q.empty())
    {
        LocInfo tmp = q.front();
        q.pop();

        int dirX[] = { 1, 0, 0, -1 };
        int dirY[] = { 0, 1, -1, 0 };

        for (int i = 0; i < 4; i++)
        {
            int locX = tmp.x + dirX[i];
            int locY = tmp.y + dirY[i];
            
            if (locX >= 0 && locX < N && locY >= 0 && locY < M)
            {
                int locDist = tmp.dist + 1;
                int locCnt = tmp.cnt;

                if (board[locX][locY] == 1) locCnt += 1;

                if (locCnt <2)
                {
                    if (visited[locX][locY][locCnt] == -1)
                    {
                        visited[locX][locY][locCnt] = locDist;
                        LocInfo loc = { locX, locY, locDist, locCnt };
                        q.push(loc);
                    }
                    else
                    {
                        if (visited[locX][locY][locCnt] > locDist)
                        {
                            visited[locX][locY][locCnt] = locDist;
                            
                            LocInfo loc = { locX, locY, locDist, locCnt };
                            q.push(loc);
                        }
                    }
                }

            }
            
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
            char tmp;
            cin >> tmp; 

            board[i][j] = tmp - '0';

            visited[i][j][0] = -1;
            visited[i][j][1] = -1;
        }
    }


    bfs();

    int case1 = visited[N - 1][M - 1][0];
    int case2 = visited[N - 1][M - 1][1];

    if (case1 == -1)
    {
        if (case2 == -1) cout << -1;
        else cout << case2;
    }
    else if (case2 == -1)
    {
        if (case1 == -1) cout << -1;
        else cout << case1;
    }
    else
    {
        if (case1 < case2) cout << case1;
        else cout << case2;
    }
}
