#include <iostream>
#include <queue>

using namespace std;

int dist[101];
int loc[101];
int N;

void bfs(int num)
{
    queue<int> q;
    q.push(num);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int next_loc = tmp + i;

            if (next_loc > 100) continue;
            next_loc = loc[next_loc];
            if (dist[next_loc] == -1)
            {
                dist[next_loc] = dist[tmp] + 1;
                q.push(next_loc);
            }
        }
    }

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int  M;

    cin >> N >> M;

    for (int i = 1; i <= 100; i++)
    {
        loc[i] = i;
        dist[i] = -1;
    }

    for (int i = 0; i < N + M; i++)
    {
        int tmp1, tmp2;

        cin >> tmp1 >> tmp2;

        loc[tmp1] = tmp2;
    }

    dist[1] = 0;
    bfs(1);

    cout << dist[100];

}
