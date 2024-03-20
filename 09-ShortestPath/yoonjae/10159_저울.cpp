#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool answer[101][101];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        answer[a][b] = true;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (k == j)
                {
                    answer[k][j] = 0;
                    continue;
                }
                if (!answer[k][j])
                {
                    if((answer[k][i] && answer[i][j]))
                        answer[k][j] = true;
                }
                    
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(answer[i][j]) answer[j][i] = true;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (!answer[i][j])
                cnt++;
        }

        if (cnt != 0)
            cnt -= 1;
        cout << cnt <<'\n';
    }
}
