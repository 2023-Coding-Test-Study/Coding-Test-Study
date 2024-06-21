#include <bits/stdc++.h>

using namespace std;

int nodes[50001];
int intensity[50001];
vector<vector<pair<int,int>>> adj(50001); // 2차원 그래프 

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) { 
    for(int i=1; i<=n; i++) intensity[i] = 1e9;
    for(auto s : summits) nodes[s] = 2; // 산봉우리 
    for(auto p: paths) { // 양방향이므로 
        adj[p[0]].push_back({p[2], p[1]}); // 0번째와 1번째를 잇는 등산로 2시간 
        adj[p[1]].push_back({p[2], p[0]});
    }
    
    priority_queue<pair<int,int>> pq;
    for(auto g: gates) { // 출입구
        intensity[g] = -1; // 출입구를 표시
        pq.push({0, g});
    }
    
    int ans_intensity = 1e9;
    int summit = 1e9;

    while(!pq.empty()) {
        auto [max_intensity, cur_node] = pq.top(); pq.pop(); 
    
        if(max_intensity > ans_intensity) continue;
        if(nodes[cur_node] == 2) { // 산봉우리 일 때 
            if(max_intensity < ans_intensity) {
                ans_intensity = max_intensity;
                summit = cur_node;
            }
            else if(max_intensity == ans_intensity && cur_node < summit) {
                summit = cur_node;
            }
            continue;
        }

        for(auto next: adj[cur_node]) {
            if(intensity[next.second] > max(max_intensity, next.first)) {
                intensity[next.second] = max(max_intensity, next.first);

                pq.push({intensity[next.second], next.second});
            } 
        }
    }

    return {summit, ans_intensity};
}
