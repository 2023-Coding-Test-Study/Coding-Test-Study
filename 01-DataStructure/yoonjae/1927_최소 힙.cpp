#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N;

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        if (tmp == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                int tmp2 = pq.top();
                cout << tmp2 << '\n';

                pq.pop();
            }
        }
        else
        {
            pq.push(tmp);
        }
    }
}