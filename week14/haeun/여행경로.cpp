#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<string, int> psi;

const int MAX = 10001;

// 노드 간의 연결 관계 (인덱스가 문자열이므로 해시에 저장)
unordered_map<string, vector<psi>> graph;

// 간선 방문 여부 저장 (티켓 사용 여부)
bool visited[MAX];
int ticketSize = 0;

// 알파벳 순으로 첫번째 경우의 수만 저장하기 위한 플래그 변수 
bool foundFirstCase = false; 

vector<string> answer;

void dfs(string now, int cnt, vector<string> cache) {
    if(cnt == ticketSize && !foundFirstCase) {
        foundFirstCase = true;
        
        // 알파벳 순으로 가장 앞서는 경우만 정답으로 저장 
        answer = cache;
        
        return;
    }
    
    for(auto edge: graph[now]){
        string name = edge.first; 
        int idx = edge.second;
        
        if(!visited[idx]){
            // 방문 처리
            visited[idx] = true; 
            cache.push_back(name);
            
            // 재귀 호출
            dfs(name, cnt + 1, cache);
            
            // 상태 복구
            cache.pop_back();
            visited[idx] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 알파벳 순으로 오름차순 정렬
    sort(tickets.begin(), tickets.end());
    
    ticketSize = tickets.size();
    
    for(int i = 0; i < tickets.size(); i++){
        string s = tickets[i][0];
        string e = tickets[i][1];

        // s에서 e로 가는 티켓 번호가 i라는 의미 
        graph[s].push_back({e, i});
    }
    
    dfs("ICN", 0, {"ICN"});
    
    return answer;
}