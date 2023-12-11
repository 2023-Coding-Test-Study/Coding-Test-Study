#include <iostream>
#include<queue>
#include <vector>

using namespace std;

int n , m;
int parent[100001];

struct RoadInfo {

    int s;  //start
    int e;  //end
    int cost;

    bool operator()(RoadInfo a, RoadInfo b) {
        if (a.cost == b.cost)
        {
            if (a.s == b.s)
            {
                return a.e > b.e;
            }
            return a.s > b.s;
        }
        return a.cost > b.cost;
    }
};

priority_queue<RoadInfo, vector<RoadInfo>, RoadInfo > q;
//vector<RoadInfo> roads;

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

long long kruskal()
{
    int max = -1;
    long long res = 0;
    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();

        int ps = find_set(tmp.s);
        int pe = find_set(tmp.e);

        if (ps == pe) continue;

        if (tmp.cost > max) max = tmp.cost;

        union_set(tmp.s, tmp.e);
        res += tmp.cost;
    }

    res -= max;

    return res;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        RoadInfo tmp;

        cin >> tmp.s >> tmp.e >> tmp.cost;

        q.push(tmp);
    }

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    long long total = kruskal();

    cout << total;
}