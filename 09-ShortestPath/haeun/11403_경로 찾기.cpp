#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 101; 
int N; 
vector<int> graph[MAX]; 
bool visited[MAX]; 

void input() {
	cin >> N;

	for(int i = 0; i < N; i++){ 
		for(int j = 0; j < N; j++){ 
			int x;
			cin >> x;
			if(x == 1) graph[i].push_back(j); 
		}
	}
}

void dfs(int x){
	// x와 연결된 인접 노드에 대한 방문 처리 
	for(int i = 0; i < graph[x].size(); i++){ 
		int y = graph[x][i]; 
		if(!visited[y]){ 
			visited[y] = true;
			dfs(y); 
		}
	}
}

void solution() {
	for(int i = 0; i < N; i++){
		// i번 노드와 연결된 노드 방문 처리 
		dfs(i);

		// i와 연결되어 있어서 방문한 노드인 경우 1 출력 
		for(int j = 0; j < N; j++) 
			cout << visited[j] << " "; 
		cout << "\n"; 

		// 방문 처리하기 위한 배열 초기화
		fill(visited, visited + MAX, false);
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
