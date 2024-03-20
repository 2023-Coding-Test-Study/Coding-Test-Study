#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n , m;
int parent[201];

int find_set(int num)
{
    if (parent[num] != num)
        parent[num] = find_set(parent[num]);
    return parent[num];
}

void union_set(int a, int b)
{
    int _a = find_set(a);
    int _b = find_set(b);

    if (_a < _b)
        parent[_b] = _a;
    else
        parent[_a] = _b;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;


    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;

            cin >> tmp;
            
            if (tmp == 1)
            {
                union_set(i, j);
            }
        }
    }

    int first;

    cin >> first;

    int prev = find_set(first);
    for (int i = 2; i <= m; i++)
    {
        int tmp;

        cin >> tmp;

        int p = find_set(tmp);

        if (prev != p)
        {
            cout << "NO";
            return 0;
        }

    }

    cout << "YES";
}