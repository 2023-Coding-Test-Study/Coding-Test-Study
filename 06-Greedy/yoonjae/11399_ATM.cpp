#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int time = 0;

        for (int j = 0; j <= i; j++)
        {
            time += v[j];
        }

        ans += time;
    }

    cout << ans;
}