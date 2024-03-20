#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;
int cnt = 0;
bool complete = false;

bool checkBlank(pair<int, int> blank)
{
    int xIndex = blank.first / 3;
    int yIndex = blank.second / 3;

    for (int i = 0; i < 9; i++)
    {
        if (board[blank.first][i] == board[blank.first][blank.second] && i != blank.second)
        {
            return false;
        }
        if (board[i][blank.second] == board[blank.first][blank.second] && i != blank.first)
        {
            return false;
        }
    }

    for (int i = 3 * xIndex; i < 3 * xIndex + 3; i++)
    {
        for (int j = 3 * yIndex; j < 3 * yIndex + 3; j++)
        {
            if (board[i][j] == board[blank.first][blank.second])
            {
                if (i != blank.first && j != blank.second)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void dfs(int depth)
{
    if (cnt == depth)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        complete = true;
        return;
    }

    for (int num = 1; num <= 9; num++)
    {
        board[blanks[depth].first][blanks[depth].second] = num;

        if (checkBlank(blanks[depth]))
        {
            dfs(depth + 1);
            
        }
        if (complete)
        {
            return;
        }
        
    }
    board[blanks[depth].first][blanks[depth].second] = 0;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                pair<int, int> tmp;
                tmp.first = i;
                tmp.second = j;
                blanks.push_back(tmp);
                cnt++;
            }
        }
    }

    dfs(0);

    return 0;
}