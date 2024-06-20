#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
map<int, queue<pair<int, int>>> rec; // map은 기본적으로 key 값을 기준으로 오름차순 정렬

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (string temp : records) {
        string time, h;
        int num;
        stringstream ss(temp);
        ss >> time >> num >> h;

				// 시간 문자열 분리 
        int hour, min;
        hour = stoi(temp.substr(0, temp.find(":")));
        min = stoi(temp.substr(temp.find(":") + 1));

        if (rec.find(num) != rec.end()) { // 기존에 차량 번호가 있다면
            rec[num].push({hour, min});
        }
        else { // 차량 번호가 없다면 
            queue<pair<int, int>> t;
            t.push({ hour,min });
            rec.insert({ num, t });
        }
    } // 입력 값 정리 

    for (auto cal : rec) { // 각 차량 번호에 대해서 
        auto q = cal.second;
        int sum = 0; // 분 최종합
        while(!q.empty()) { // 각 시간에 대해서 
            auto start = q.front(); q.pop();
            pair<int, int> end;
            if (q.empty()) { // 23:59가 종료 
                end = { 23, 59 };
            }
            else {
                end = q.front(); q.pop();
            }

            // 간격 계산 
            int tH = end.first - start.first;
            int tM = end.second - start.second;

            sum += tH * 60 + tM;
        }

        int bill = 0;
        double calT = 0; // 계산해야 하는 시간 
        if (sum <= fees[0]) { // 기본요금을 넘지 않는 경우
            answer.push_back(fees[1]); // 기본요금 
        }
        else { // 기본 요금을 넘는 경우
            bill = fees[1];
            calT = sum - fees[0];
            bill += ceil((calT / fees[2])) * fees[3];
            answer.push_back(bill);
        }
    }

    return answer;
}

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
// }
