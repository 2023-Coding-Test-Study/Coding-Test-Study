#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1001; 
const int INF = 1e9; 
vector<pii> graph[MAX]; 
int dist[MAX];
int dp[MAX];
int N, M; 

// T에서 모든 노드까지의 최단 거리 구하기 
// 합리적인 이동 경로 개수를 저장하는 DP 테이블 채우기 
void dijkstra(int t) {
	priority_queue<pii, vector<pii>, greater<pii>> pq; 
	pq.push({0, t}); // 거리를 기준으로 최소 힙
	dist[t] = 0; 
	dp[t] = 1; 

	while(!pq.empty()){
		auto cur = pq.top(); 
		pq.pop(); 

		int d = cur.first; 
		int now = cur.second; 
		
        // 현재 노드에 대해 처리한 경우 패스 
		if(d > dist[now]) continue;
		
        // 인접 노드 검사 
		for(auto edge: graph[now]){
			int adj = edge.first; 
			int cost = edge.second; 
			
			int nd = d + cost; 
			if(dist[adj] > nd){
             	// 최단 거리 테이블 갱신 
				dist[adj] = nd; 
				pq.push({nd, adj}); 
			}

			// 현재 노드보다 최단 거리가 짧은 경우
            // 합리적인 이동 경로에 포함시키고 DP 테이블 갱신 
			if(d > dist[adj]){
				dp[now] += dp[adj];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	fill(dist, dist + MAX, INF);

	for(int i = 0; i < M; i++){
		int a, b, c; 
		cin >> a >> b >> c; 
        
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	dijkstra(2);
    
	cout << dp[1];
	
	return 0;
}