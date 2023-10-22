#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, N;

    cin >> H >> W >> N;

    vector<pair<int, int>>v;
    for (int i = 0; i < N; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        v.push_back(make_pair(tmp1, tmp2));
    }
    
    int res = 0;

    int length = v.size();

    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            int A = v[i].first;
            int B = v[i].second;
            int C = v[j].first;
            int D = v[j].second;

            if (A+C <=W || B+D <= H)
            {
                if (A <=W && C <=W && B <= H && D <= H)
                {
                    int total = A * B + C * D;

                    if (total > res)
                    {
                        res = total;
                    }
                }
            }

            if (A + D <= W || B + C<= H)
            {
                if (A <= W && D <= W && B <= H && C <= H)
                {
                    int total = A * B + C * D;

                    if (total > res)
                    {
                        res = total;
                    }
                }
            }

            if (B + C <= W || A + D <= H)
            {
                if (B <= W && C <= W && A <= H && D <= H)
                {
                    int total = A * B + C * D;

                    if (total > res)
                    {
                        res = total;
                    }
                }
            }
            if (B + D<= W || A + C <= H)
            {
                if (B <= W && D <= W && A <= H && C <= H)
                {
                    int total = A * B + C * D;

                    if (total > res)
                    {
                        res = total;
                    }
                }
            }
        }
    }

    cout << res;
}