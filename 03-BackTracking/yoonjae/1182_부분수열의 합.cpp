#include <iostream>
#include <vector>

using namespace std;

int Max;
int cnt = 0;
int S;

vector<int> v;
vector<int> nums;

void res()
{
    int sum = 0;
    for (auto item : v)
    {
        sum += item;
    }
    if (sum == S)
    {
        cnt++;
    }
}

void dfs(int depth, int start)
{
    if (depth == Max)
    {
        res();
        return;
    }

    int size = nums.size();

    for (int i = start; i < size; i++)
    {
        v.push_back(nums[i]);
        dfs(depth + 1, i + 1);
        v.pop_back();
    }

    return;
}

int main()
{
    int N;
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        int tmp;

        cin >> tmp;

        nums.push_back(tmp);
    }

    for (int i = 1; i <= N; i++)
    {
        Max = i;

        dfs(0, 0);
    }
    
    cout << cnt;

    return 0;
}