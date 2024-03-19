#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int temp = 0;

	fill(dist, dist + 20001, -1);
	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]); // 양방향이므로 
	} // 간선의 개수 파악

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int e = graph[cur][i];
			if (dist[e] >= 0) continue; // 이미 방문했다면 
			q.push({ e });
			dist[e] = dist[cur] + 1;
			if (temp < dist[e]) {
				temp = dist[e];
				answer = 1; // 초기화 
			}
			else if (temp == dist[e]) answer++;
		}
	}
	
	return answer;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << solution(6, { {3, 6} ,{4, 3}, {3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });
}
