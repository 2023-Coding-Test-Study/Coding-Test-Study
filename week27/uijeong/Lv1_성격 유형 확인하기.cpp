#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> test(4, vector<int>(2, 0)); 

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int check = 0;
    string s_c = "RTCFJMAN"; // 01 / 23 / 45 / 67
    
    for(int i=0; i < survey.size(); i++){
        if(choices[i] < 4){ // 비동의 관련
            check = 0; // 문자열 앞 
        }
        else if(choices[i] > 4){ // 동의 관련
            check = 1; // 문자열 뒤 
        }
        else{ // 4인 경우
            check = -1; // 아무 점수 못 받음 
        }
        
        if(check != -1){ // -1이 아닐 때 
            char ans = survey[i][check]; // 해당 질문의 앞뒤 중 하나
            string s = "";
            s += ans; // 문자열로 받음 
            
            int f = s_c.find(s); // find로 위치 찾기 
            test[f/2][f%2] += abs(choices[i]-4); 
        }
        else{
            continue;
        }
    }
    
    for(int i = 0; i < 4; i++){
        if(test[i][0] >= test[i][1]){
            answer += s_c[2*i+0]; // "RTCFJMAN"; // 01 / 23 / 45 / 67
        }    
        else if(test[i][0] < test[i][1]){
            answer += s_c[2*i+1];
        }
    }
    
    return answer;
}
