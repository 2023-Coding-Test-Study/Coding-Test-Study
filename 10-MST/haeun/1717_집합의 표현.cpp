#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1000001; 
int N, M;
vector<pair<int, pii>> edges; 
int parent[MAX]; 

void input() {
	cin >> N >> M; 

	// 부모 노드 번호를 자기 자신으로 초기화 
	for(int i = 0; i <= N; i++){
		parent[i] = i; 
	}

    // 간선 정보 입력 
	for(int i = 0; i < M; i++){
		int op, a, b; 
		cin >> op >> a >> b;
		edges.push_back({op, {a, b}});
	}
}

// 루트 노드에 도달할 때까지 재귀 호출하다가 
// 빠져나오면서 부모 배열에 루트 노드 번호 저장 
int findRootNode(int x){
	if(x == parent[x]) return x; 
	return parent[x] = findRootNode(parent[x]); 
}

// 루트 노드를 갱신하며 두 집합을 합친다. 
// 작은 번호가 부모 노드가 되도록 
void unionSet(int a, int b){
	if(a < b) parent[b] = a; 
	else parent[a] = b; 
}

void solution() {
	for(auto edge: edges){
		int op = edge.first; 
		int a = edge.second.first; 
		int b = edge.second.second; 

		int ra = findRootNode(a); 
		int rb = findRootNode(b);
		
		if(op == 0){
			unionSet(ra, rb);
		}else{
			if(ra == rb){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
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
