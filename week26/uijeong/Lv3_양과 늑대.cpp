#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> inf;
vector<vector<int>> ed(18, vector<int>({}));
int ans = 0;

void dfs(int cur, int sheepCount, int wolfCount, queue<int> q){
    if(inf[cur] == 0){ // 양일때
        sheepCount++;
        ans = max(ans, sheepCount);
    }
    else{ // 늑대일 때
        wolfCount++;
    }
    
    if(sheepCount <= wolfCount) return; // 종료 조건
    
    for(int i = 0; i < ed[cur].size(); i++){
        q.push(ed[cur][i]); // 갈 수 있는 노드 push 
    }
    
    for(int i=0; i < q.size(); i++){
        int next = q.front();
        q.pop();
        dfs(next, sheepCount, wolfCount, q);
        q.push(next); // 즉 dfs 돌고 나서 갈 수 있는 거 다시 추가 
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    inf = info;
    
    for(int i=0; i < inf.size(); i++){
        ed[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> q;
    dfs(0, 0, 0, q);
    
    return ans;
}
