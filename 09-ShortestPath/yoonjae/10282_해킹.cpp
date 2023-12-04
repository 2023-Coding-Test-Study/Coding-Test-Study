#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define largeNum 1000000000

using namespace std;

int N, D, C;
vector<vector<pair<int, int>>> answer;
int dist[10001];
bool visited[10001];

void bfs(int num)
{
    queue<int> q;
    q.push(num);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        int minValue = largeNum;
        int minIndex = N + 1;

        for (const auto& item : answer[tmp])
        {
            dist[item.first] = min(dist[item.first], dist[tmp] + item.second);
        }

        for (int i = 1; i <= N; i++)
        {
            if (minValue > dist[i] && !(visited[i]))
            {
                minValue = dist[i];
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

    int T;

    cin >> T;

    for (int test = 0; test < T; test++)
    {
        cin >> N >> D >> C;

        for (int i = 0; i <= N; i++)
        {
            vector<pair<int, int>> vec;
            answer.push_back(vec);
        }

        for (int i = 0; i < D; i++)
        {
            int a, b, s;

            cin >> a >> b >> s;

            answer[b].push_back({ a, s });
        }


        for (int i = 1; i <= N; i++)
        {
            dist[i] = largeNum;
        }

        dist[C] = 0;

        bfs(C);

        int cnt = 0;
        int maxValue = -1;
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] != largeNum)
            {
                cnt++;

                maxValue = max(maxValue, dist[i]);
            }
  
        }

        cout << cnt << ' ' << maxValue << '\n';

        for (int i = 1; i <= N; i++)
        {
            dist[i] = 0;
            visited[i] = false;
        }

        answer.clear();
    }
    
}