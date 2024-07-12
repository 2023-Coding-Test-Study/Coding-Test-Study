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

const int MAX = 401;
int N, K, S;
int graph[MAX][MAX];
vector<pii> ans;

void input(){
	cin >> N >> K;

	for(int i = 0; i < K; i++){
		int a, b;
		cin >> a >> b;
		graph[a][b] = -1;
		graph[b][a] = 1;
	}

	cin >> S;
	for(int i = 0; i < S; i++){
		int x, y;
		cin >> x >> y;
		ans.push_back({x, y});
	}
}

void floyd(){
	// 경유점을 가장 바깥 for문에서 돌린다.
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i == j) continue;
				if(i == k || j == k) continue;
				
				if(graph[i][j] == 0){
					if(graph[i][k] == -1 && graph[k][j] == -1){
						graph[i][j] = -1;
					}
					else if(graph[i][k] == 1 && graph[k][j] == 1){
						graph[i][j] = 1;
					}
				}
			}
		}
	}
}

void solution(){
	floyd(); 

	for(auto p: ans){
		int a = p.first;
		int b = p.second;
		cout << graph[a][b] << "\n";
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