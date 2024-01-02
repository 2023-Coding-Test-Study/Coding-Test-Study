#include <bits/stdc++.h>

using namespace std;

int max_value = -1;
int max_service = -1;
void sale(int cnt, int M, vector<vector<int>> users, vector<int> emoticons);
vector<int> temp;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    sale(0, emoticons.size(), users, emoticons);
    answer.push_back(max_service);
    answer.push_back(max_value);
    
    return answer;
}

void sale(int cnt, int M, vector<vector<int>> users, vector<int> emoticons){
    if(cnt == M){
        int count = 0; // 임시 count
        int bill = 0; // 임시 총 구매 
        for(int i=0; i < users.size(); i++){
            int cost = 0; // 임시 사용자 구매 비용 
            for(int j=0; j < emoticons.size(); j++){
                if(users[i][0] <= temp[i]){
                    // sale이 가능하다면  
                    cost += emoticons[i]*(100-temp[i])/100; // 할인된 가격 더해주기 
                }
            }
            
            if(cost >= users[i][1]) count++;
            else bill += cost; 
        }
        
        if(count > max_service){
            max_service = count;
            max_value = bill;
        }
        else if(count == max_service && bill > max_value) max_value = bill;
    }
    
    for(int i=4; i>=1; i--){
        temp.push_back(i*10); // 할인율 결정 
        sale(cnt+1, M, users, emoticons);
        temp.pop_back(); // 초기화 
    }
}
