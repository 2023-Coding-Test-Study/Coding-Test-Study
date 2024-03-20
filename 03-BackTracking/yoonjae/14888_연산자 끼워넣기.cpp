#include <iostream>
#include <vector>

using namespace std;

int Max = -1000000000;
int Min = 1000000000;
int N;


vector<int> v;
vector<int> nums;
vector<int> oper; // 1== '+' , 2 == '-', 3 == '*', 4 == '/'
vector<bool> visited;

void res()
{
    int result = nums[0];
    for (int k=0; k <N-1; k++)
    {
        switch (v[k])
        {
        case 1 :
            result += nums[k + 1];
            break;
        case 2:
            result -= nums[k + 1];
            break;
        case 3:
            result *= nums[k + 1];
            break;
        case 4 :
            result /= nums[k + 1];
            break;
        }

    }

    //cout << result << '\n';

    if (result > Max)
    {
        Max = result;
    }

    if (result < Min)
    {
        Min = result;
    }
}

void dfs(int depth)
{
    if (depth == N-1)
    {
        res();
        return;
    }

    for (int i = 0; i < N-1; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(oper[i]);
            dfs(depth + 1);
            v.pop_back();
            visited[i] = false;

        }
        
    }

    return;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;

        cin >> tmp;

        nums.push_back(tmp);
    }

    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int tmp;
        cin >> tmp;

        for (int j = 0; j < tmp; j++)
        {
            oper.push_back(cnt);
            visited.push_back(false);
        }

        cnt++;
    }

    dfs(0);

    cout << Max << '\n' << Min;

    return 0;
}