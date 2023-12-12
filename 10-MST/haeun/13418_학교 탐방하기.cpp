#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1001; 
int N, M; 
vector<pair<int, pii>> edges; 
int parent[MAX]; 

void input() {
	cin >> N >> M; 

	// 부모 노드 배열 초기화
	for(int i = 0; i <= N; i++){ 
		parent[i] = i; 
	}

	// (M + 1)개의 간선 정보 저장 -> 간선 개수 유의하기!! 
	for(int i = 0; i < M + 1; i++){ 
		int a, b, c; 
		cin >> a >> b >> c; 
		edges.push_back({c, {a, b}}); 
	}
}

// 루트 노드를 찾을 때까지 재귀 호출하고 
// 배열에 루트 노드 번호를 저장한다. 
int findRootNode(int x){
	if(x == parent[x]) return x;
	return parent[x] = findRootNode(parent[x]);
}

// 사이클을 만들지 않는 두 집합을 합친다. 
void unionSet(int a, int b) {
	if(a < b) parent[b] = a; 
	else parent[a] = b; 
}

int kruskalForUphill() {
	int cnt = 0;

	// 오르막길부터 먼저 MST에 추가하기 
	for(int i = 0; i < edges.size(); i++){
		int flag = edges[i].first; 
		int a = edges[i].second.first; 
		int b = edges[i].second.second;
		
		int ra = findRootNode(a);
		int rb = findRootNode(b);

		if(ra != rb){
			unionSet(ra, rb);
			if(flag == 0) cnt++;
		}
	}
	
	return cnt * cnt; 
}

int kruskalForDownhill() {
	int cnt = 0;

	// 내리막길부터 먼저 MST에 추가하기 
	for(int i = edges.size() - 1; i >= 0; i--){
		int flag = edges[i].first; 
		int a = edges[i].second.first; 
		int b = edges[i].second.second;

		int ra = findRootNode(a);
		int rb = findRootNode(b);

		if(ra != rb){
			unionSet(ra, rb);
			if(flag == 0) cnt++;
		}
	}
	
	return cnt * cnt; 
}

void initParentArray() {
	for(int i = 0; i <= N; i++){ 
		parent[i] = i; 
	}
}

void solution() {
	sort(edges.begin(), edges.end());
	
	int maxFatigue = kruskalForUphill();
	initParentArray();
	int minFatigue = kruskalForDownhill(); 

	cout << maxFatigue - minFatigue; 
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	solution(); 
	
	return 0; 
}
