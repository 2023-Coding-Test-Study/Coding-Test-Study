#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> pii; 

const int MAX = 20001;
vector<int> graph[MAX];
bool visited[MAX];
int d[MAX]; // 최단 거리 테이블 

int bfs(int start){
    queue<int> q; 
    q.push(start);
    visited[start] = true;
    d[start] = 0;
    
    int maxVal = -1; 
    while(!q.empty()){
        int num = q.front();
        q.pop();
    
        for(int adj: graph[num]){
            if(!visited[adj]){
                q.push({adj});
                visited[adj] = true;
                d[adj] = d[num] + 1; // 이동 거리 갱신
                
                if(maxVal < d[adj]){
                    maxVal = d[adj];   
                }
            }
        }
    }
    
    return maxVal; 
}

int solution(int n, vector<vector<int>> edge) {
    for(auto node: edge){
        int s = node[0];
        int e = node[1];
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    int maxVal = bfs(1);
    
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == maxVal) {
            cnt++;
        }
    }
    
    return cnt;
}