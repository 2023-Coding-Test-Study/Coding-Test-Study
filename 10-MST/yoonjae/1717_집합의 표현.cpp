#include <iostream>

using namespace std;

int n,m;
int parent[1000001];

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

    for (int i = 0; i < m; i++)
    {
        int flag, a, b;

        cin >> flag >> a >> b;

        if (flag)
        {
            int _a = find_set(a);
            int _b = find_set(b);

            if (_a == _b)
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else
        {
            union_set(a, b);
        }
    }
  
}