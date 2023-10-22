#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int res = -1;
    for (int i = 0; i < N; i++)
    {
        int A = v[i];
        for (int j = i+1; j < N; j++)
        {
            int B = v[j];
            for (int k = j + 1; k < N; k++)
            {
                int C = v[k];

                int tmp2 = A + B + C;

                if (tmp2 == M)
                {
                    res = M;
                    break;
                }
                else if (tmp2 < M)
                {
                    if (res < tmp2)
                    {
                        res = tmp2;
                    }
                }

            }

            if (res == M)
            {
                break;
            }
        }

        if (res == M)
        {
            break;
        }
    }

    cout << res;
}