#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, L;
vector<int> v;

bool chk(int mid) {
    int cnt = 0;
    int size = v.size();
    for (int i = 1; i < size; i++) {
        int dist = v[i] - v[i - 1];
        cnt += dist / mid;
        if (dist % mid == 0) {
            cnt--;
        }
    }
    return cnt > M;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);



    cin >> N >> M >> L;

    v.push_back(0);
    v.push_back(L);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int start = 1;
    int end = L;
    int mid, res;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int cnt = 0;
        int size = v.size();
        for (int i = 1; i < size; i++) {
            int dist = v[i] - v[i - 1];
            cnt += dist / mid;
            if (dist % mid == 0) {
                cnt--;
            }
        }
        
        if (cnt > M)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
            res = mid;
        }
    }

    cout << res;

}