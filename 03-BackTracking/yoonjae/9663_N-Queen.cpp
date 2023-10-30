#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt=0;
vector<pair<int, int>> v;
vector<int> visited;

void dfs(int depth)
{
    if (depth == N)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        bool check = true;
        for (int j = 0; j < depth; j++)
        {
            if (abs(i - visited[j]) != abs(depth - j) && visited[j] != i)
            {
                
            }
            else
            {
                check = false;
            }
        }

        if (check)
        {
            visited[depth] = i;
            dfs(depth + 1);
        }
    }

    return;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        visited.push_back(-1);
    }

    dfs(0);

    cout << cnt;

    return 0;
}