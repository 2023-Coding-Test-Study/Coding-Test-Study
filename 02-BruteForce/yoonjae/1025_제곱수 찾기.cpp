#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int res = -1;

//완전제곱수
void CheckSquare(int num)
{
    int tmp = sqrt(num);
    int value = pow(tmp, 2);

    if (num == value)
    {
        if (num > res)
        {
            res = num;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> vec;
    
    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            v.push_back(s[j] - '0');
        }

        vec.push_back(v);
    }



    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                for (int l = 0; l < M; l++)
                {
                    if (i == k && j == l)
                    {
                        continue;
                    }

                    int num = vec[i][j]*10 +vec[k][l];
                    
                    CheckSquare(num);

                    int addRow = k - i;
                    int addCol = l - j;

                    int row = k + addRow;
                    int col = l + addCol;

                    while (row >= 0 && row < N && col >= 0 && col < M)
                    {
                        num = num * 10 + vec[row][col];

                        CheckSquare(num);

                        row += addRow;
                        col += addCol;
                    }

                }
            }

            CheckSquare(vec[i][j]);

        }
    }

    cout << res;
}