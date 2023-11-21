#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int size = triangle.size();

    vector<vector<int>> dp;

    for (int i = 0; i < size; i++)
    {
        int tmp = triangle[i].size();
        vector<int> vec;
        for (int j = 0; j < tmp; j++)
        {
            vec.push_back(0);
        }
        dp.push_back(vec);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        int tmp = triangle[i].size();

        for (int j = tmp - 1; j >= 0; j--)
        {
            if (i == size - 1)
                dp[i][j] = triangle[i][j];
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
    }
    return dp[0][0];
}