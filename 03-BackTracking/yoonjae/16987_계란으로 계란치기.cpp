#include <iostream>
#include <vector>

using namespace std;

int N;
int Max = 0;

vector<pair<int, int>> eggs;

void res()
{
    int cnt = 0;
    for (pair<int, int> item : eggs)
    {
        if (item.first <= 0)
        {
            cnt++;
        }
    }

    if (cnt > Max)
    {
        Max = cnt;
    }
}

void dfs(int depth)
{
    if (depth > N)
    {
        return;
    }


    for (int i = 0; i < N; i++)
    {
        if (eggs[depth].first <= 0)
        {
            dfs(depth + 1);
        }
        else if (depth == i || eggs[i].first <=0)
        {
            continue; 
        }
        else
        {
            eggs[depth].first -= eggs[i].second;
            eggs[i].first -= eggs[depth].second;

            dfs(depth + 1);

            eggs[depth].first += eggs[i].second;
            eggs[i].first += eggs[depth].second;    
        }
    }

    res();

    return;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int dur, weight;
        cin >> dur >> weight;
        eggs.push_back({ dur, weight });
    }

    dfs(0);

    cout << Max;

    return 0;
}