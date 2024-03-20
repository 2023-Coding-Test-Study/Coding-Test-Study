#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    vector<int>v;

    cin >> N;

    int* dp = new int[N];
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            dp[i] = v[i];
        else if (i == 1)
            dp[i] = dp[i - 1] + v[i];
        else if (i == 2)
            dp[i] = max(v[i-1] + v[i], v[i-2] + v[i]);
        else
        {
            dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);
        }
    }

    cout << dp[N-1];

}