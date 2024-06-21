#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int answer[101][101];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            answer[i][j] = 1000000000;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        answer[a][b] = min(answer[a][b], c);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (k == j) answer[k][j] = 0;
                answer[k][j] = min(answer[k][j], answer[k][i] + answer[i][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (answer[i][j] == 1000000000)
            {
                answer[i][j] = 0;
            }
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}
