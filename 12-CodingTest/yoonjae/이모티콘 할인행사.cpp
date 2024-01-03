#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dis[4] = { 10, 20, 30, 40 };
int num = -1;
int total = -1;
int rate[8];

vector<vector<int>> vec_users;
vector<int> vec_emot;

void checkBest(int tmp_num, int tmp_total)
{
    if (tmp_num > num)
    {
        num = tmp_num;
        total = tmp_total;
    }
    else if (tmp_num == num)
    {
        if (tmp_total > total)
        {
            total = tmp_total;
        }
    }
}

void calTotalPrice()
{
    int join_num = 0;
    int price = 0;


    for (const vector<int>& user : vec_users)
    {
        bool join = false;
        int tmp_price = 0;

        for (int i=0; i< vec_emot.size(); i++)
        {
            if (user[0] <= rate[i])
            {
                tmp_price +=  ((100 - rate[i]) * vec_emot[i]) / 100;

                if (tmp_price >= user[1])
                {
                    tmp_price = 0;
                    join = true;
                    break;
                }
            }
        }

        if (join)
        {
            join_num++;
        }

        price += tmp_price;

    }
    checkBest(join_num, price);
}

void dfs(int depth, int size)
{
    if (depth == size)
    {
        calTotalPrice();
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        rate[depth] = dis[i];
        dfs(depth + 1, size);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    for (auto item : users)
    {
        vector<int> vec;
        for (auto tmp : item)
        {
            vec.push_back(tmp);
        }
        vec_users.push_back(vec);
    }

    for (auto item : emoticons)
    {
        vec_emot.push_back(item);
    }

    dfs(0, emoticons.size());

    answer.push_back(num);
    answer.push_back(total);

    return answer;
}

int main()
{
    vector<int> ans = solution({{10, 100}}, {10,10,10,10,5000});

    for (auto item : ans)
    {
        cout << item << '/';
    }
    
}