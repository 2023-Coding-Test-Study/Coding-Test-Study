#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    vector <string> results;
    stack<int> stk;
    vector<pair<int, int>> mates;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            stk.push(i);
        }

        if (str[i] == ')')
        {
            mates.push_back(make_pair(stk.top(), i));
            stk.pop();
        }
    }

    int len = mates.size();

    for (int i = 1; i <= len; i++) {
        vector<bool> v(len - i, false);
        v.insert(v.end(), i, true);
        do {
            string tmp = str;
            for (int j = 0; j < len; j++) {
                if (v[j])
                {
                    tmp[mates[j].first] = ' ';
                    tmp[mates[j].second] = ' ';
                }
            }

            tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());

            results.push_back(tmp);
            
        } while (next_permutation(v.begin(), v.end()));

    }


    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    for (string item : results)
    {
        cout << item << '\n';
    }
}