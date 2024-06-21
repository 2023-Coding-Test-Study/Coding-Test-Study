#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    
    int GoodWordCount = 0;
    for (int i = 0; i < N; i++)
    {
        stack<char> stk;
        string str;

        cin >> str;

        for (char item : str)
        {
            if (stk.empty())
            {
                stk.push(item);
            }
            else
            {
                if (stk.top() == item)
                {
                    stk.pop();
                }
                else
                {
                    stk.push(item);
                }
            }
        }

        if (stk.empty())
        {
            GoodWordCount++;
        }

    }

    cout << GoodWordCount;
}