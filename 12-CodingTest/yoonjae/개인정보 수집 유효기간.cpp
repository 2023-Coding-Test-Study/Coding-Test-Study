#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    //today 입력
    string today_buf;
    int int_today[3];
    char sep = '.';
    istringstream iss(today);
    int cnt = 0;
    while (getline(iss, today_buf, sep)) {
        int_today[cnt] = stoi(today_buf);
        cnt++;
    }
    
    //terms 입력
    map <string, int> map_terms;
    for (const string & item : terms)
    {
        istringstream iss(item);
        int tmp_cnt = 0;
        char blank = ' ';
        string tmp_buf;
        string letter;
        int months;
        while (getline(iss, tmp_buf, blank))
        {
            if (tmp_cnt == 0)
            {
                letter = tmp_buf;
            }
            else
            {
                months = stoi(tmp_buf);
                map_terms.insert({ letter, months });
            }
            tmp_cnt++;
        }
    }

    //체크

    int num = 1;
    for (const string& item : privacies)
    {
        int item_date[3];
        string term;

        string pri_buf;
        istringstream iss(item);
        int item_cnt = 0;
        string last_buf;
        while (getline(iss, pri_buf, sep)) {

            if (item_cnt != 2)
            {
                item_date[item_cnt] = stoi(pri_buf);
                item_cnt++;
            }
            else
            {
                last_buf = pri_buf;
            }
        }

        istringstream last_iss(last_buf);
        int last_cnt = 0;
        char blank = ' ';
        string tmp_buf;
        while (getline(last_iss, tmp_buf, blank))
        {
            if (last_cnt == 0)
            {
                item_date[2] = stoi(tmp_buf);
                last_cnt++;
            }
            else
            {
                term = tmp_buf;
            }
        }

        // 유통기한 덧셈 처리
        item_date[1] += map_terms[term];
        if (item_date[1]> 12)
        {
            if (item_date[1] % 12 == 0)
            {
                item_date[0] += item_date[1] / 12-1;
                item_date[1] = 12;
            }
            else
            {
                item_date[0] += item_date[1] / 12;
                item_date[1] = item_date[1] % 12;
            }
            
        }

        //오늘 날짜와 비교
        if (item_date[0] < int_today[0])
        {
            answer.push_back(num);
        }
        else if (item_date[0] == int_today[0])
        {
            if (item_date[1] < int_today[1])
            {
                answer.push_back(num);
            }
            else if (item_date[1] == int_today[1])
            {
                if (item_date[2] <= int_today[2])
                {
                    answer.push_back(num);
                }
            }
        }

        num++;

    }

    return answer;
}