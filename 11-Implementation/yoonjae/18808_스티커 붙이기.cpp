#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
int maxValue = -1;
int board[41][41];
int sticker[101][11][11];
vector<pair<int,int>> st_size;

bool checkArea(queue<pair<int, int>> &q,int index)
{
    int x_width = st_size[index].first;
    int y_width = st_size[index].second;
    for (int x = 1; x <= n - x_width + 1; x++)
    {
        for (int y = 1; y <= m - y_width + 1; y++)
        {
            bool flag = true;
            for (int i = 1; i <= x_width; i++)
            {
                for (int j = 1; j <= y_width; j++)
                {
                    int curX = x + i - 1;
                    int curY = y + j - 1;

                    
                    if (sticker[index][i][j] == 1)
                    {
                        if (board[curX][curY] == 1)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            board[curX][curY] = sticker[index][i][j];
                            q.push({ curX, curY });
                        }
                    }
                }
            }

            if (!flag)
            {
                //back to board
                while (!q.empty())
                {
                    auto item = q.front();
                    q.pop();
                    
                    board[item.first][item.second] = 0;
                }
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}

void detach(queue<pair<int, int>>& q)
{
    while (!q.empty())
    {
        auto item = q.front();
        q.pop();

        board[item.first][item.second] = 0;
    }
}

void rotate(int index)
{
    int x_width = st_size[index].first;
    int y_width = st_size[index].second;
    vector<vector<int>> v;

    for (int i = 0; i <= y_width; i++)
    {
        vector<int>vec;
        for (int j = 0; j <= x_width; j++)
        {
            vec.push_back(0);
        }
        v.push_back(vec);
    }
    
    for (int i = 1; i <= x_width; i++)
    {
        for (int j = 1; j <= y_width; j++)
        {
            v[j][x_width-i+1] = sticker[index][i][j];
        }
    }

    for (int i = 1; i <= y_width; i++)
    {
        for (int j = 1; j <= x_width; j++)
        {
            sticker[index][i][j] = v[i][j];
        }
    }

    st_size[index].first = y_width;
    st_size[index].second = x_width;

}

int scanArea()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] != 0) res++;
        }
    }

    return res;
}

void attach(int depth)
{
    if (depth == k)
    {
        maxValue = max(scanArea(), maxValue);
        return;
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < 4; i++)
    {
        bool res = checkArea(q, depth);

        if (!res)
            rotate(depth);
        else break;
    }
    
    attach(depth + 1);
    detach(q);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int cnt = 0; cnt < k; cnt++)
    {
        int x_size;
        int y_size;

        cin >> x_size >> y_size;

        for (int i = 1; i <= x_size; i++)
        {
            for (int j = 1; j <= y_size; j++)
            {
                cin >> sticker[cnt][i][j];
            }
        }

        st_size.push_back({ x_size, y_size });
    }

    attach(0);

    int total = maxValue;

    cout << total;
}