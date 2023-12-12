#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 100001; 
int N, M; 
vector<pair<int, pii>> edges; 
int parent[MAX]; 
int answer = 0; 

void input() {
	cin >> N >> M; 

	// 부모 노드 배열 초기화 
	for(int i = 1; i <= N; i++){
		parent[i] = i; 
	}

	// 간선 정보 저장 
	for(int i = 0; i < M; i++){
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

void solution() {
	// 간선 비용을 기준으로 오름차순 정렬
	sort(edges.begin(), edges.end());

	// 간선 비용이 작은 것부터 MST에 포함시키기 
	int maxCost = 0;
	for(int i = 0; i < M; i++){
		int cost = edges[i].first; 
		int a = edges[i].second.first; 
		int b = edges[i].second.second; 

		// 사이클을 형성하지 않는 경우만 합친다.
		int rootA = findRootNode(a);
		int rootB = findRootNode(b);
		
		if(rootA != rootB){
			unionSet(rootA, rootB); 
			maxCost = max(maxCost, cost); 
			answer += cost; 
		}
	}

	// MST에 포함되는 간선 중에서 비용이 제일 큰 것은 제외한다. 
	cout << answer - maxCost;
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	solution(); 
	
	return 0; 
}
