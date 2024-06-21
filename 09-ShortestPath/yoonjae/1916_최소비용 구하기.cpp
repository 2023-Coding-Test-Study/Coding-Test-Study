#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int answer[1001][1001];
bool visited[1001];

void bfs(int num)
{
    queue<int> q;
    q.push(num);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        int minValue = 1000000000;
        int minIndex = N + 1;
        for (int i = 1; i <= N; i++)
        {
            if (i == tmp) continue;

            answer[num][i] = min(answer[num][i], answer[num][tmp] + answer[tmp][i]);

            if (minValue > answer[num][i] && !visited[i])
            {
                minValue = answer[num][i];
                minIndex = i;
            }
        }

        if (minIndex != N + 1)
        {
            q.push(minIndex);
            visited[minIndex] = true;
        }

    }
}

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

    int start, end;
    cin >> start >> end;

    for (int i = 1; i <= N; i++)
    {
        answer[i][i] = 0;
    }

    bfs(start);

    cout << answer[start][end];
}