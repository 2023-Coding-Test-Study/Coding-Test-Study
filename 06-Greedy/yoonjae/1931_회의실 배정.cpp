#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> conf;

bool compare(pair<long long, long long> first, pair<long long, long long> second)
{
    if (first.second == second.second)
        return first.first < second.first;

    return first.second < second.second;
}

int solution() {
    int answer = 0;

    long long lastTime = -1;

    for (auto& item : conf)
    {
        if (item.first >= lastTime)
        {
            lastTime = item.second;
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long start, end;
        cin >> start >> end;
        conf.push_back(make_pair(start, end));
    }

    sort(conf.begin(), conf.end(), compare);

    int answer = solution();

    cout << answer;
}