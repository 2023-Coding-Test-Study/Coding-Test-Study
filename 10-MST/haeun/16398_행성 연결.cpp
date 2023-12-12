#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1001; 
int N; 
vector<pair<int, pii>> edges; 
int parent[MAX];

int findRootNode(int x){
	if(x == parent[x]) return x; 
	return parent[x] = findRootNode(parent[x]);
}

void unionSet(int a, int b){ 
	int ra = findRootNode(a);
	int rb = findRootNode(b);
	
	if(ra < rb) parent[rb] = ra; 
	else parent[ra] = rb; 
}

void input() {
	cin >> N; 

	for(int i = 1; i <= N; i++){
		parent[i] = i;
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			int cost;
			cin >> cost;

			// 동일한 간선 정보가 중복되지 않도록 
			// 대각선 위쪽에 있는 비용만 저장한다. 
			if(i < j) edges.push_back({cost, {i, j}});
		}
	}
}

void solution() {
	sort(edges.begin(), edges.end());

	// 간선 비용이 작은 것부터 MST에 포함시키기 
	long long answer = 0; 
	
	for(auto edge: edges){
		int cost = edge.first; 
		int a = edge.second.first; 
		int b = edge.second.second;

		// 루트 노드가 서로 다른 두 집합을 합친다. 
		if(findRootNode(a) != findRootNode(b)){ 
			unionSet(a, b); 
			answer += cost; 
		}
	}

	cout << answer; 
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	solution(); 
	
	return 0; 
}
