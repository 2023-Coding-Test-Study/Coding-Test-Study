#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    vector <pair<long long, long long>> vil;
    vector<long long>sum;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        vil.push_back(make_pair(tmp1, tmp2));
    }

    sort(vil.begin(), vil.end());

    sum.push_back(vil[0].second); 
    for (int i = 1; i < N; i++)
    {
        long long tmp = vil[i].second;
        sum.push_back(sum[i-1] + tmp);
    }

    int start = 0;
    int end = N-1;
    int mid;
    int res = vil[N-1].first;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (sum[mid] >= sum[N - 1] - sum[mid])
        {
            end = mid - 1;
            if (res > vil[mid].first)
            {
                res = vil[mid].first;
            }
        }
        else
        {
            start = mid + 1;
        }
        
    }

    cout << res;

}