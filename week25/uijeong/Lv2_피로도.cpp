#include <string>
#include <vector>

using namespace std;

vector<vector<int>> d;
int s = 0;
int K;
bool vis[8]; // 던전 방문 여부
int answer = 0; // 방문할 수 있는 최대 던전 수 

void dfs(int cnt, int t, int c){
    // 탐색한 던전 수, 현재 피로도, 방문 가능 던전 수 
    if(cnt >= s){ // 모든 경우를 다 방문
        answer = max(answer,c);
        return;
    }
    
    for(int i=0; i < s; i++){
        if(vis[i]){
            // 이미 방문했다면
            continue;
        }
        
        vis[i] = true;
        if(d[i][0] <= t){ // 최소 필요도가 작은 경우 -> K가 아니라 t....
            dfs(cnt+1, t-d[i][1], c+1); // 던전 방문
        }
        else{
            dfs(cnt+1, t, c);
        }
        vis[i] = false; // 원상복귀
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    K = k;
    d = dungeons;
    s =  d.size();
    
    dfs(0, K, 0);
    return answer;
}
