#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 20001; 
const int INF = 1e9;
int V, E, start; 
vector<pii> graph[MAX];
int dist[MAX];

void input(){
	cin >> V >> E >> start;

	fill_n(dist, V + 1, INF);

	for(int i = 0; i < E; i++){
		int u, v, w; 
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
}

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
    // 출발 노드로부터의 거리, 자신의 노드 번호 
	pq.push({0, start});
	dist[start] = 0;

	while(!pq.empty()){
		auto now = pq.top(); 
		int d = now.first; 
		int num = now.second; 
		pq.pop(); 

		// 한번 처리된 것은 패스 
		if(dist[num] < d) continue; 

		for(auto edge: graph[num]){
            // 인접 노드의 번호와 가중치 
			int nextNum = edge.first; 
			int cost = edge.second;
			int newDist = d + cost;

			// 인접 노드를 거쳐가는 게 더 빠른지 검사 
			if(dist[nextNum] > newDist){
				dist[nextNum] = newDist;
				pq.push({newDist, nextNum});
			}
		}
	}	
}

void printAnswer() {
	for(int i = 1; i <= V; i++){
		if(dist[i] == INF){
			cout << "INF\n";
		}else{
			cout << dist[i] << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dijkstra();

	printAnswer();
	
	return 0;
}