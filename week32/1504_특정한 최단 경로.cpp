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

const int MAX = 805;
const int INF = 1e8;
int N, E, v1, v2;
vector<pii> graph[MAX];
int dist[MAX];

void input(){
	cin >> N >> E; 

	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	cin >> v1 >> v2;
}


void dijkstra(int start) {
	fill(dist, dist + N + 1, INF);
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, start});
	dist[start] = 0; 

	while(!pq.empty()){
		auto now = pq.top(); 
		int d = now.first;
		int num = now.second;
		pq.pop(); 

		if(dist[num] < d) continue; 

		for(auto edge: graph[num]){
			int next = edge.first;
			int cost = edge.second;
			int newCost = d + cost;

			if(dist[next] > newCost){
				dist[next] = newCost;
				pq.push({newCost, next});
			}
		}
	}
}

void solution(){
	dijkstra(1);
	int onetov1 = dist[v1];
	int onetov2 = dist[v2];

	dijkstra(v1);
	int v1tov2 = dist[v2];
	int v1toN = dist[N];

	dijkstra(v2);
    int v2toN = dist[N];

	// 간선 가중치의 최대 합은 2억
	int sum1 = onetov1 + v1tov2 + v2toN;
	int sum2 = onetov2 + v1tov2 + v1toN;
	int ans = min(sum1, sum2);
	
	if(ans >= INF){
		cout << "-1\n";
	}else{
		cout << ans;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution(); 
	
	return 0;
}