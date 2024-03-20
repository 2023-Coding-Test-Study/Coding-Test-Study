#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<long long> q1;
queue<long long> q2;
int solution(vector<int> queue1, vector<int> queue2) {

    long long sum1 = 0;
    long long sum2 = 0;

    for (long long item : queue1)
    {
        q1.push(item);
        sum1 += item;
    }

    for (long long item : queue2)
    {
        q2.push(item);
        sum2 += item;
    }

    int max_count = queue1.size() * 3;
    int count = 0;

    while (true)
    {
        if (sum1 > sum2)
        {
            auto item = q1.front();
            q1.pop();
            q2.push(item);

            sum1 -= item;
            sum2 += item;
            count++;
        }
        else if (sum2 > sum1)
        {
            auto item = q2.front();
            q2.pop();
            q1.push(item);

            sum2 -= item;
            sum1 += item;
            count++;
        }
        else
        {
            break;
        }

        if (count == max_count) return -1;
    }

    return count;
}
