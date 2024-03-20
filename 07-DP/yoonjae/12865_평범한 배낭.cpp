#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[102][100002];

bool compare(pair<int, int> start, pair<int, int> end)
{
    if (start.first == end.first)
        return start.second > end.second;

    return start.first < end.first;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    vector<pair<int, int>>v;

    cin >> N >> K;

    v.push_back(make_pair(0, 0));

    for (int i = 0; i < N; i++)
    {
        int W, V;
        cin >> W >> V;
        v.push_back(make_pair(W, V));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (!(j < v[i].first))
            {
                dp[i][j] = max(dp[i - 1][j - v[i].first] + v[i].second, dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }

        }
    }

    cout << dp[N][K];

}