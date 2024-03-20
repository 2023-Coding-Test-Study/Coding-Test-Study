#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1001; 
const int INF = 1e9; 
int N, M;
int startNode, endNode;
vector<pii> graph[MAX]; 
int d[MAX]; 

void input() {
	cin >> N >> M; 

	// 최단 거리 테이블 초기화 
	fill_n(d, N + 1, INF); 

	// 간선 정보 입력 
	for(int i = 0; i < M; i++){
		int a, b, c; 
		cin >> a >> b >> c;

		// a에서 b로 가는 비용이 c (가중치가 있는 유향 그래프)
		graph[a].push_back({b, c});
	}

	// 최소 비용을 알고 싶은 출발 & 도착 노드 
	cin >> startNode >> endNode; 
}

void dijkstra() {
	// 출발 노드로부터의 거리가 작을수록 우선순위가 높은 최소 힙 
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	// 출발 노드에 대한 초기화 
	pq.push({0, startNode}); // 거리, 노드 번호
	d[startNode] = 0;

	while(!pq.empty()){
		int curDist = pq.top().first; 
		int curNum = pq.top().second; 
		pq.pop(); 

		// 최단 거리 테이블에 저장된 값이 더 작으면 
        // 방문한 적이 있는 노드이므로 넘어간다. 
		if(curDist > d[curNum]) continue; 

		// curNum 노드와 연결된 인접 노드 검사 
		for(auto edge: graph[curNum]){ 
			// 인접 노드의 번호, 비용 
			int adjNum = edge.first; 
			int cost = edge.second; 
			int newCost = curDist + cost;

			// curNum 노드를 거쳐서 
			// 인접 노드로 가는 비용이 더 작은 경우 
			if(d[adjNum] > newCost){
				// 최단 거리 테이블 갱신 
				d[adjNum] = newCost; 

				// adjNum 노드의 갱신 정보를 큐에 삽입 
				pq.push({newCost, adjNum}); 
			}
		}
	}
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	dijkstra();

	// 출발 노드에서 도착 노드까지의 최단 거리 출력 
	cout << d[endNode]; 
	
	return 0; 
}
