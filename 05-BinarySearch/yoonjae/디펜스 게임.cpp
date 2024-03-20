#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int start = 0;
    int end = enemy.size();

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = k;
        int num = n;
        vector<int> tmp{ enemy };
        sort(tmp.begin(), tmp.begin() + mid);
        for (int i = 0; i < mid; i++)
        {
            if (num >= tmp[i])
            {
                num -= tmp[i];
            }
            else
            {
                cnt -= mid - i;
                break;
            }
        }

        if (cnt >= 0)
        {
            if (answer < mid)
            {
                answer = mid;
            }
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }

    return answer;
}