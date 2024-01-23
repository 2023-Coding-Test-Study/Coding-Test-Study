#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<string, int> psi; // 공항 이름, 간선 번호

const int MAX = 10001;
unordered_map<string, vector<psi>> graph;
bool visited[MAX];

vector<string> answer;
int maxLength = 0; // 그래프 가지의 최대 깊이 (간선의 최대 개수)

// 가능한 경우의 수 중에 첫번째 것만 저장하기 위한 플래그 변수 
bool foundFirstCase = false; 

void dfs(string now, int cnt, vector<string> cache) {
    if(cnt == maxLength && !foundFirstCase) {
        foundFirstCase = true;
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
    maxLength = tickets.size();
    
    // 노드 간의 연결 관계 -> 해시에 저장
    for(int i = 0; i < tickets.size(); i++){
        string s = tickets[i][0];
        string e = tickets[i][1];
        graph[s].push_back({e, i});
    }
    
    dfs("ICN", 0, {"ICN"});
    
    return answer;
}