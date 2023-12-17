#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, c_size;
int minValue = 65;
int board[9][9];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct LocInfo {

    int x;  
    int y;  
    int num;
};

vector<LocInfo> cameras;

void seekArea(queue<pair<int,int>> &v, int x, int y, int index, int num)
{
    x += dx[index];
    y += dy[index];

    if (num == 9)
    {
        while (x <= n && x >= 1 && y >= 1 && y <= m)
        {
            if (board[x][y] == 6)
                break;

            if (board[x][y] == 0)
            {
                board[x][y] = num;
                v.push({ x, y });
            }

            x += dx[index];
            y += dy[index];
        }
    }
    else if (num == 0)
    {
        while (!v.empty())
        {
            pair<int, int > tmp = v.front();
            v.pop();
            board[tmp.first][tmp.second] = num;
        }
        
    }
    
}

int checkArea()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == 0) res++;
        }
    }

    return res;
}

void minArea(int depth)
{
    if (depth >= c_size)
    {
        minValue = min(checkArea(), minValue);
        return;
    }
    
    int num = cameras[depth].num;
    int idx = cameras[depth].x;
    int idy = cameras[depth].y;

    queue<pair<int, int>> v;

    switch (num)
    {
    case 1:
        for (int cnt = 0; cnt < 4; cnt++)
        {
 
            seekArea(v, idx, idy, cnt, 9);
            minArea(depth + 1);
            seekArea(v, idx, idy, cnt, 0);
        }
        break;
    case 2:
        for (int cnt = 0; cnt < 2; cnt++)
        {
            seekArea(v, idx, idy, cnt, 9);
            seekArea(v, idx, idy, cnt+2, 9);
            minArea(depth + 1);
            seekArea(v, idx, idy, cnt, 0);
            seekArea(v, idx, idy, cnt+2, 0);
        }
        break;
    case 3:
        for (int cnt = 0; cnt < 4; cnt++)
        {
            seekArea(v, idx, idy, cnt, 9);
            seekArea(v, idx, idy, (cnt + 1) % 4, 9);
            minArea(depth + 1);
            seekArea(v, idx, idy, cnt, 0);
            seekArea(v, idx, idy, (cnt +1) %4, 0);
        }
        break;
    case 4:
        for (int cnt = 0; cnt < 4; cnt++)
        {
            seekArea(v, idx, idy, cnt, 9);
            seekArea(v, idx, idy, (cnt + 1) % 4, 9);
            seekArea(v, idx, idy, (cnt + 2) % 4, 9);
            minArea(depth + 1);
            seekArea(v, idx, idy, cnt, 0);
            seekArea(v, idx, idy, (cnt + 1) % 4, 0);
            seekArea(v, idx, idy, (cnt + 2) % 4, 0);
        }
        break;
    case 5:
        seekArea(v, idx, idy, 0, 9);
        seekArea(v, idx, idy, 1, 9);
        seekArea(v, idx, idy, 2, 9);
        seekArea(v, idx, idy, 3, 9);
        minArea(depth + 1);
        seekArea(v, idx, idy, 0, 0);
        seekArea(v, idx, idy, 1, 0);
        seekArea(v, idx, idy, 2, 0);
        seekArea(v, idx, idy, 3, 0);
        break;
    default:
        break;
    }

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            cin >> tmp;

            board[i][j] = tmp;

            if (tmp != 0 && tmp != 6)
            {
                LocInfo loc;
                loc = {i,j,tmp};
                cameras.push_back(loc);
            }
        }
    }

    c_size = cameras.size();

    minArea(0);

    int total = minValue;

    cout << total;
}