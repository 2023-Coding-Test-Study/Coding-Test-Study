#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int total = 0;
char board[13][7];
bool visited[13][7];
int dx[] = {1, -1, 0, 0};
int dy[] = { 0, 0, 1, -1 };
char curValue = ' ';
queue<pair<int, int>> q;
vector<pair<int, int>> locs;

void clear()
{
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            visited[i][j] = false;
        }
    }
}

void down()
{
    for (int j = 1; j <= 6; j++)
    {
        queue<char> letters;
        for (int i = 12; i >=1; i--)
        {
        
            if (board[i][j] != '.')
            {
                letters.push(board[i][j]);
                board[i][j] = '.';
            }
        }

        int idx = 12;
        while (!letters.empty())
        {
            auto item = letters.front();
            letters.pop();

            board[idx][j] = item;
            idx--;
        }
    }
}

bool bfs()
{
    while (!q.empty())
    {
        auto item = q.front();
        q.pop();
        locs.push_back({ item.first, item.second });

        for (int i = 0; i < 4; i++)
        {
            int curX = item.first + dx[i];
            int curY = item.second + dy[i];

            if (!visited[curX][curY])
            {
                if (board[curX][curY] == curValue)
                {
                    q.push({ curX, curY });
                    visited[curX][curY] = true;
                }
            }
        }
    }

    if (locs.size() >= 4)
    {
        for (auto item : locs)
        {
            board[item.first][item.second] = '.';
        }

        return true;
    }
    else return false;
}

bool search()
{
    bool pop = false;
    for (int i = 12; i >=1; i--)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (board[i][j] != '.')
            {
                q.push({ i, j });
                visited[i][j] = true;
                curValue = board[i][j];
                bool flag = bfs();

                if (flag) pop = true;

                locs.clear();
                clear();
                curValue = ' ';
            }
            
        }
    }
    down();

    return pop;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cin >> board[i][j];
        }
    }

    while (true)
    {
        bool flag = search();

        if (!flag) break;
        else total++;
    }

    cout << total;
}