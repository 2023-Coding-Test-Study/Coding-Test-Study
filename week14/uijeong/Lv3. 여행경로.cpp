#include <bits/stdc++.h>

using namespace std;

vector<string> answer;
bool vis[10001];
int flag = false;
int cnt = 0;

void dfs(string cur, vector<vector<string>> tickets){
    if(cnt == tickets.size()){
        // cnt에 먼저 도달한 경우 그냥 dfs를 벗어남!   
        flag = true;
    }
    answer.push_back(cur);
    for(int i=0; i < tickets.size(); i++){ // 경로 수 만큼 
        if(!vis[i] && tickets[i][0] == cur){ // 해당 티켓을 사용하지 않았고 혹은 출발지라면 
            vis[i] = true;
            cnt++; // 티켓 한 장 사용
            dfs(tickets[i][1], tickets);
            
            // 모든 공항을 방문하지 않았는데 길이 끊긴 경우에 대해서 백트래킹 처리 필요!
						// 또한 a -> b로 가는 경로가 여러 가지 이므로! 
            if(!flag){
                answer.pop_back();
                vis[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); // 알파벳 순서로 정렬 
    dfs("ICN", tickets);
    
    return answer;
}
