#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<int, int>> stk;
    vector <int> towers;

    int N;

    cin >> N;

    vector <int> results(N, 0);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        towers.push_back(tmp);
    }

    for (int i=0; i<N; i++)
    {
        while (true)
        {
            if (stk.empty())
            {
                stk.push(make_pair(i, towers[i]));

                results[i] = 0;
                break;
            }

            if (stk.top().second < towers[i])
            {
                stk.pop();
            }
            else
            {
                results[i] = stk.top().first +1;
                stk.push(make_pair(i, towers[i]));
                break;
            }
        }
       
    }

    for (int item : results)
    {
        cout << item << ' ';
    }
    
}