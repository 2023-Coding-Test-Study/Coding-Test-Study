#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<long long, long long> first, pair<long long, long long> second)
{
    if (first.second == second.second)
        return first.first > second.first;

    return first.second > second.second;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        long long ans = 0;
        int max = -1;
        for (int j = n-1; j >= 0; j--)
        {
            if (v[j] > max) max = v[j];
            ans += max - v[j];
        }
        
        cout << ans << '\n';
    }

}