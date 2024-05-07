#include <string>
#include <vector>
using namespace std;

const int MAX = 18;
vector<int> tree[MAX];
vector<int> type; 
bool visited[MAX][MAX][MAX];
int ans = 0;

void dfs(int idx, int sheep, int wolf){
    // 루트 노드를 거쳐갈 때마다 최댓값 갱신 
    if(idx == 0){
        ans = max(ans, sheep);
    }
    
    for(auto next: tree[idx]){
        if(type[next] == 0){
            if(!visited[next][sheep + 1][wolf]){
                // 방문 처리 
                visited[next][sheep + 1][wolf] = true; 
                // 노드 재방문 시, 양과 늑대 개수에 변화가 없도록 -1로 표시 
                type[next] = -1; 
                
                // 양이 있는 노드로 이동 
                dfs(next, sheep + 1, wolf);
                
                // 상태 복구 
                visited[next][sheep + 1][wolf] = false; 
                type[next] = 0;
            }
        }
        else if(type[next] == 1){
            if(!visited[next][sheep][wolf + 1] && sheep > wolf + 1){
                // 방문 처리 
                visited[next][sheep][wolf + 1] = true; 
                // 노드 재방문 시, 양과 늑대 개수에 변화가 없도록 -1로 표시 
                type[next] = -1; 
                
                // 늑대가 있는 노드로 이동 
                dfs(next, sheep, wolf + 1);
                
                // 상태 복구 
                visited[next][sheep][wolf + 1] = false; 
                type[next] = 1;
            }
        }else{
            // 양 또는 늑대를 처리하여 아무것도 없는 노드인 경우 
            if(!visited[next][sheep][wolf]){
                visited[next][sheep][wolf] = true; 
                dfs(next, sheep, wolf);
                visited[next][sheep][wolf] = false; 
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {    
    // 부모와 자식 간의 양방향 연결 
    for(auto e: edges){
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
    }
    
    // 전역 변수 초기화 
    type = info;
    
    // 루트 노드에 대한 처리 
    type[0] = -1; 
    visited[0][1][0] = true; 
    dfs(0, 1, 0);
    
    return ans;
}