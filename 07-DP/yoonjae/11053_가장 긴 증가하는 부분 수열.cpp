#include <iostream>
#include <vector>

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

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }

        if (max < dp[i])
            max = dp[i];
    }

    cout << max;

}