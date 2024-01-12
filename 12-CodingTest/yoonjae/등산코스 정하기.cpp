#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> res; // num, intensity
vector<pair<int, int>> node[50001];
bool summit[50001];
int dist[50001]; //최소 가중치


void search(vector<int>& gates)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (auto item : gates) {
        q.push({ item, 0 });
        dist[item] = 0;
    }

    while (!q.empty()) {
        int num = q.top().first;
        int cost = q.top().second;

        q.pop();

        //최소가 아닌 경우
        if (res.first != -1 && res.second < cost) continue;

        //최소면 갱신
        if (summit[num]) {
            // 갱신
            if (res.first == -1 || res.second > cost) {
                res.first = num;
                res.second = cost;
            }
            else if (res.second == cost && res.first > num) res.first = num;
            continue;
        }

        //탐색
        for (int i = 0; i < node[num].size(); i++) {
            int next = node[num][i].first;
            int nCost = node[num][i].second; // 그 노드로 가는 비용
            nCost = max(nCost, cost); //더 높은 비용

            // dist에 저장된 비용보다 작은 경우
            if (dist[next] == -1 || nCost < dist[next]) {
                // 갱신 후 큐에 삽입
                dist[next] = nCost;
                q.push({ next,nCost });
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    for (auto& item : paths)
    {
        node[item[0]].push_back({ item[1], item[2] });
        node[item[1]].push_back({ item[0], item[2] });
    }

    for (auto& item : summits)
    {
        summit[item] = true;
    }

    for (int i=0; i<50001; i++)
    {
        dist[i] = -1;
    }

    res = { -1, -1 };

    search(gates);

    answer.push_back(res.first);
    answer.push_back(res.second);

    return answer;
}
