#include <iostream>
#include<queue>
#include <vector>

using namespace std;

int n, m;
int parent[1001];

struct RoadInfo {

    int s;  //start
    int e;  //end
    int cost;   // up : 0, down : 1

    bool operator()(RoadInfo a, RoadInfo b) {
        if (a.cost == b.cost)
        {
            if (a.s == b.s)
            {
                return a.e > b.e;
            }
            return a.s > b.s;
        }
        return a.cost < b.cost;
    }
};

struct RoadReverseInfo {

    int s;  //start
    int e;  //end
    int cost;   // up : 0, down : 1

    bool operator()(RoadReverseInfo a, RoadReverseInfo b) {
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
priority_queue<RoadReverseInfo, vector<RoadReverseInfo>, RoadReverseInfo > rev;

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
    long long cnt = 0;
    long long res = 0;
    long long best;
    long long worst;
    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();

        int ps = find_set(tmp.s);
        int pe = find_set(tmp.e);

        if (ps == pe) continue;
        
        union_set(tmp.s, tmp.e);

        if (tmp.cost == 0) cnt++;
    }

    best = cnt * cnt;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    cnt = 0;

    while (!rev.empty())
    {
        auto tmp = rev.top();
        rev.pop();

        int ps = find_set(tmp.s);
        int pe = find_set(tmp.e);

        if (ps == pe) continue;

        union_set(tmp.s, tmp.e);

        if (tmp.cost == 0) cnt++;
    }

    worst = cnt * cnt;

    return worst - best;

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i <= m; i++)
    {
        RoadInfo tmp;

        cin >> tmp.s >> tmp.e >> tmp.cost;

        q.push(tmp);

        RoadReverseInfo re_tmp;
        re_tmp.s = tmp.s;
        re_tmp.e = tmp.e;
        re_tmp.cost = tmp.cost;

        rev.push(re_tmp);
    }

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    long long total = kruskal();

    cout << total;
}