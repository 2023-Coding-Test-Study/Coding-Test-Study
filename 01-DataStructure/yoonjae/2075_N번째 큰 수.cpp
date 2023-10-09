#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack <int> stk;
    vector <int> res;

    int N;
    int count = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;

            if (i == 0)
            {
                res.push_back(tmp);
                if (j == N-1)
                {
                    sort(res.begin(), res.end(), greater<>());
                }
            }
            else
            {
                for (int j = N - 1; j >= 0; j--)
                {
                    if (res[j] > tmp)
                    {
                        res.insert(res.begin() + j+1, tmp);
                        res.pop_back();
                        break;
                    }
                    else
                    {
                        if (j == 0)
                        {
                            res.insert(res.begin(), tmp);
                            res.pop_back();
                        }
                    }

                    
                }
            }
            
        }     
    }

    cout << res[N-1];
}