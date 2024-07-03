#include <bits/stdc++.h>

using namespace std;

int N, st, ed, ans, cnt;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> st >> ed;
        v.push_back({ st, 1 });
        v.push_back({ ed,-1 });
    }

    sort(v.begin(), v.end());


    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i].second;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';

}
