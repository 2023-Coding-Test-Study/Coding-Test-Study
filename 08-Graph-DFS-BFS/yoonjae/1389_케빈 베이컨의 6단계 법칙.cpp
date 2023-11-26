#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int visited[101];
int N;

int bfs(int num)
{
    queue<int> q;
    q.push(num);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (num == i) continue;
            if (tmp == i) continue;

            if (arr[tmp][i] == 1)
            {
                if (visited[i] == 0)
                {
                    visited[i] = visited[tmp] + 1;

                    q.push(i);
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        res += visited[i];
        visited[i] = 0;
    }

    return res;

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int  M;

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int tmp1, tmp2;

        cin >> tmp1 >> tmp2;

        arr[tmp1][tmp2] = 1;
        arr[tmp2][tmp1] = 1;
    }

    int min = INT32_MAX;
    int minIndex = INT32_MAX;
    for (int i = 1; i <= N; i++)
    {
        int ans = bfs(i);

        if (ans < min)
        {
            min = ans;
            minIndex = i;
        }
        
    }

    cout << minIndex;

}
