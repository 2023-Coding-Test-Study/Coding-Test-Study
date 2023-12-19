#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M, x, y, K;
int board[21][21];
int aspect[5][5];

void Roll_North()
{
    for (int i = 1; i < 4; i++)
    {
        aspect[i - 1][2] = aspect[i][2];
    }

    aspect[3][2] = aspect[0][0];
    aspect[0][0] = aspect[0][2];
    aspect[0][2] = 0;
}

void Roll_South()
{
    for (int i = 3; i >=1 ; i--)
    {
        aspect[i + 1][2] = aspect[i][2];
    }

    aspect[1][2] = aspect[0][0];
    aspect[0][0] = aspect[4][2];
    aspect[4][2] = 0;
}

void Roll_East()
{
    for (int j = 3; j >= 1; j--)
    {
        aspect[2][j+1] = aspect[2][j];
    }

    aspect[2][1] = aspect[0][0];
    aspect[0][0] = aspect[2][4];
    aspect[2][4] = 0;
}

void Roll_West()
{
    for (int j = 1; j <= 4; j++)
    {
        aspect[2][j-1] = aspect[2][j];
    }

    aspect[2][3] = aspect[0][0];
    aspect[0][0] = aspect[2][0];
    aspect[2][0] = 0;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;

        switch (tmp)
        {
        case 1:
            if (y + 1 >= M) continue;
            y += 1;
            Roll_East();
            break;
        case 2:
            if (y - 1 < 0) continue;
            y -= 1;
                
            Roll_West();
            break;
        case 3:
            if (x - 1 < 0) continue;
            x -= 1;
            Roll_North();
            break;
        case 4:
            if (x + 1 >= N) continue;
            x += 1;
            Roll_South();
            break;
        }

        if (board[x][y] != 0)
        {
            aspect[0][0] = board[x][y];
            board[x][y] = 0;
        }
        else
        {
            board[x][y] = aspect[0][0];
        }

        cout << aspect[2][2] << '\n';
    }
}