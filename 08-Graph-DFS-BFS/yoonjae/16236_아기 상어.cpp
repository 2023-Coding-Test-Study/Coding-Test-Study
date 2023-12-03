#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[21][21];
int N;
bool visited[401];

int curLoc;
int curSize;
int curNum;

void ResetVisited()
{

    for (int i = 0; i < N * N; i++)
    {
        visited[i] = false;
    }
}


//먹은 물고기 수
void AddNum()
{
    curNum++;
    if (curNum == curSize)
    {
        curNum = 0;
        curSize ++;
        if (curSize == 9) curSize = 8;
    }
}


int bfs(int num)
{
    int cnt = 0;
    queue<pair<int, int>> q; // 위치, 거리
    q.push({num, 0});

    while (!q.empty())
    {
        pair<int , int> tmp = q.front();
        q.pop();

        int fishSize = board[tmp.first / N][tmp.first % N];

        if (fishSize < curSize && fishSize != 0)
        {
            pair<int, int > min = tmp;
            while (!q.empty())
            {
                pair<int, int> tmp2 = q.front();
                q.pop();

                int tmp2fishSize = board[tmp2.first / N][tmp2.first % N];

                if (min.second >= tmp2.second && min.first > tmp2.first && tmp2fishSize != 0 && tmp2fishSize < curSize)
                {
                    min = tmp2;
                }

            }

            AddNum();
            board[curLoc / N][curLoc % N] = 0;
            board[min.first / N][min.first %N] = 9;
            cnt += min.second;
            ResetVisited();
            q.push({ min.first, 0 });
            curLoc = min.first;
            visited[curLoc] = true;
            continue;
        }

        int dirX[] = { -1, 0, 0, 1 };
        int dirY[] = { 0, -1, 1, 0 };

        int locs[4] = { 0,0,0,0 };
        for (int i = 0; i < 4; i++)
        {
            int x = (tmp.first / N) + dirX[i];
            int y = (tmp.first % N) + dirY[i];

            int loc = x * N + y;

            if (x >= 0 && x < N && y >= 0 && y < N)
            {
                if (board[x][y] == 9) continue;

                if (board[x][y] <= curSize && !visited[loc])
                {
                    q.push({ loc, tmp.second + 1 });
                    visited[loc] = true;
                }

            }
        }
    }

    return cnt;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    curLoc =-1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;

            board[i][j] = tmp;

            if (tmp == 9) curLoc = i * N + j;
        }
    }

    curSize = 2;
    curNum = 0;
    int ans = bfs(curLoc);

    cout << ans;

}
