#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 50001;
vector<pii> graph[MAX];

// 출입구에서 다른 지점까지의 최소 intensity 저장 
int intensity[MAX] = {-1, };

bool isSummit[MAX];
vector<int> answer;

void dijkstra(vector<int> gates){
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 최소 힙 
    vector<pii> temp; // 비용, 산봉우리 번호
    
    // 모든 출입구를 시작 정점으로 둔다. 
    for(auto num: gates){
        pq.push({0, num}); // 최소 intensity, 노드 번호  
        intensity[num] = 0;
    }
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        // 이미 최솟값이 갱신된 노드인 경우 패스 
        if(cost > intensity[now]) continue; 
        
        // 산봉우리에 도달한 경우, 가능한 경우의 수 추가 
        if(isSummit[now]){
            temp.push_back({cost, now});
            continue;
        }
        
        for(auto edge: graph[now]){
            int to = edge.first;
            int weight = edge.second;
            
            if(intensity[to] == -1 || intensity[to] > max(cost, weight)){
                intensity[to] = max(cost, weight);
                pq.push({intensity[to], to});
            }
        }
    }
    
    sort(temp.begin(), temp.end());
    answer.push_back(temp[0].second);
    answer.push_back(temp[0].first);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(auto path: paths){
        int start = path[0];
        int end = path[1];
        int cost = path[2];
        
        // 양방향 연결
        graph[start].push_back({end, cost});
        graph[end].push_back({start, cost});
    }
    
    for(auto num: summits){
        isSummit[num] = true; 
    }
    
    dijkstra(gates);
    
    return answer; 
}