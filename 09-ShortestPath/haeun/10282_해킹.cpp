#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 10001; 
const int INF = 1e9; 
int N, D, C; 
vector<pii> graph[MAX]; 
int d[MAX]; 

void input() {
	// 노드 개수, 간선 개수, 출발 노드 
	cin >> N >> D >> C; 

	// 최단 거리 테이블 초기화 
	fill_n(d, N + 1, INF); 

	// 간선 정보 입력 
	for(int i = 0; i < D; i++){  
		int a, b, s; 
		cin >> a >> b >> s;

		// b에서 a로 감염되는 시간 s초 (간선의 방향 주의!!!)
		graph[b].push_back({a, s}); 
	}
}

void dijkstra() {
	// 출발 노드로부터의 거리가 작을수록 우선순위가 높은 최소 힙
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	// 출발 노드에 대한 초기화 
	pq.push({0, C}); // 거리, 노드 번호 
	d[C] = 0; 

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

				// adjNum 노드에 대한 정보 큐에 삽입 
				pq.push({newCost, adjNum}); 
			}
		}
	}
}

void printAnswer() {
	int cnt = 0, time = 0;

	for(int i = 1; i <= N; i++){
		if(d[i] != INF) {
			cnt++;
			time = max(time, d[i]); 
		}
	}

	cout << cnt << " " << time << "\n"; 
}

void initGraphArray() {
	for(int i = 1; i <= N; i++){ 
		graph[i].clear(); 
	}
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; 
	cin >> T; 

	while(T--){
		input();
		dijkstra();
		printAnswer(); 
		initGraphArray(); 
	}
	
	return 0; 
}
