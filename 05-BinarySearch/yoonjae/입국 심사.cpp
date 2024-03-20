#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = (*max_element(times.begin(), times.end())) * (long long)n;

    long long start = 1;
    long long end = answer;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long cnt = 0;

        for (long long item : times)
        {
            cnt += mid / item;
        }

        if (cnt >= n)
        {
            if (answer > mid)
            {
                answer = mid;
            }

            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }


    }


    return answer;
}