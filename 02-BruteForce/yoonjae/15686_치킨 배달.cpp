#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int M;

vector<int> dfs_vec;
vector<pair<int, int>> chicken_loc;
vector<vector<pair<int, int>>> chicken_dist;
vector<int>results;

void res()
{
    int sum = 0;
    //조합으로 얻은 값만큼 더해서 결과에 넣기
    for (auto distances : chicken_dist)
    {
        for (auto dist : distances)
        {
            bool insert = false;
            for (auto item : dfs_vec)
            {
                if (dist.first == item)
                {
                    sum += dist.second;
                    insert = true;
                    break;
                }
            }

            if (insert)
            {
                break;
            }
            
        }

    }
   
    results.push_back(sum);
}

void dfs(int depth, int start)
{
    int size = chicken_loc.size();

    if (depth == M)
    {
        res();
        return;
    }

    for (int i = start; i < size; i++)
    {
        dfs_vec.push_back(i);
        dfs(depth + 1, i + 1);
        dfs_vec.pop_back();
    }

    return;
}

bool compare(pair<int, int> start, pair<int, int>end)
{
    return start.second < end.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N >> M;

    vector<vector<int>> vec;
    
    // 치킨 집 체크하기
    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            if (tmp == 2)
            {
                chicken_loc.push_back(make_pair(i + 1, j + 1));
            }
        }

        vec.push_back(v);
    }

    //집 기준 치킨 거리 정렬해서 저장
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vec[i][j] == 1)
            {
                vector<pair<int, int>> home_vec;
                int count = 0;
                for (pair<int, int>item : chicken_loc)
                {
                    int dist = abs(item.first - (i + 1)) + abs(item.second - (j + 1));
                    
                    home_vec.push_back(make_pair(count, dist));
                    count++;
                }

                sort(home_vec.begin(), home_vec.end(), compare);

                chicken_dist.push_back(home_vec);
            }
        }
    }

    dfs(0, 0);

    // 결과 정렬
    sort(results.begin(), results.end());

    cout << results[0];
}