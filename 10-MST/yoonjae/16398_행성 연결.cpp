#include <iostream>
#include<queue>

using namespace std;

int n;
int cost[1001][1001];
int visited[1001];

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            a.first > b.first;
        return a.second > b.second;
    }
};

void prim(int num)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare > q;
    q.push({ num, 0 });

    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();

        if (visited[tmp.first] != -1) continue;
        visited[tmp.first]= tmp.second;
        
        
        for (int i = 1; i <= n; i++)
        {
            if (i == tmp.first) continue;
            
            if (visited[i] == -1)
            {
                q.push({ i, cost[tmp.first][i] });
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }

        visited[i] = -1;
    }
    prim(1);

    long long total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += visited[i];
    }
  

    cout << total;
}