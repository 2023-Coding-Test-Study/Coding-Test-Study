#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int calcFee(vector<int> fees, int time){
    if(time <= fees[0]){
        return fees[1];
    }else{
        return fees[1] + ceil((time - fees[0]) / (double)fees[2]) * fees[3];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer; // 각 차량에 대한 주차 요금 
    set<string> cars; // 차량 번호 (낮은 순으로)
    vector<int> parking; // 누적 주차 시간
    
    // 차량 번호 파악 (중복 제거)
    for(auto record: records){
        stringstream ss(record);
        string a, b, c;
        ss >> a >> b >> c; 
        cars.insert(b);
    }
    
    parking.resize(cars.size(), 0);
    
    // 각 차량의 누적 주차 시간 계산
    for(auto it = cars.begin(); it != cars.end(); it++){
        int idx = distance(cars.begin(), it);
        stack<int> st;
        
        for(auto record: records){
            stringstream ss(record);
            string time, num, dir;
            ss >> time >> num >> dir;
            
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            int minutes = h * 60 + m;
            
            if(*it == num){
                if(dir == "IN"){
                    st.push(minutes);
                }else{
                    if(!st.empty()){
                        int parkingTime = minutes - st.top();
                        parking[idx] += parkingTime;
                        st.pop();
                    }
                }
            }
        }
        
        if(!st.empty()){
            int parkingTime = 1439 - st.top();
            parking[idx] += parkingTime;
            st.pop();
        }
    }
    
    // 그 시간에 따른 주차 요금 일괄 계산
    for(auto time: parking){
        int fee = calcFee(fees, time);
        answer.push_back(fee);
    }
    
    return answer;
}