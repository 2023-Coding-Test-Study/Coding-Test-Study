#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map> 
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

const int MAX = 21; 
int N, M; 
int answer = 1e9; 
char graph[MAX][MAX]; 
vector<pii> coin;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void input() {
	cin >> N >> M; 

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> graph[i][j]; 

			// 두 동전의 위치 저장 (탐색의 시작점)
			if(graph[i][j] == 'o'){
				coin.push_back({i, j});
			}
		}
	}
}

bool isRangeOver(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

// 두 동전의 좌표, 이동 횟수 (버튼 누른 횟수), 이동 방향 
void dfs(pii coinA, pii coinB, int cnt, int dir){
	// 기존의 최솟값 보다 많이 눌리면 
	// 다음 경우의 수로 pass 
	if(answer < cnt) return; 

	// 마지막 이동 횟수가 10번인 경우
	// 최솟값 갱신 후 다음 경우의 수로 pass
	if(cnt > 10){
		answer = min(answer, cnt);
		return; 
	}

	int ax = coinA.first, ay = coinA.second; 
	int bx = coinB.first, by = coinB.second; 
	
	int nax = ax + dx[dir];
	int nay = ay + dy[dir];

	int nbx = bx + dx[dir];
	int nby = by + dy[dir];

	// 동전 두개 모두 떨어진 경우
	if(isRangeOver(nax, nay) && isRangeOver(nbx, nby)) return;

	// 동전 A만 떨어진 경우 
	if(isRangeOver(nax, nay) && !isRangeOver(nbx, nby)){
		answer = min(answer, cnt);
		return; 
	}

	// 동전 B만 떨어진 경우 
	if(!isRangeOver(nax, nay) && isRangeOver(nbx, nby)){
		answer = min(answer, cnt);
		return; 
	}

	// 두개의 동전 모두 떨어지지 않은 경우
	// 계속해서 이동한다.

	// 벽을 만난 경우 이동하지 못한다. 
	if(graph[nax][nay] == '#'){
		nax = ax; 
		nay = ay; 
	}

	if(graph[nbx][nby] == '#'){
		nbx = bx; 
		nby = by; 
	}

	// 그 다음 방향에 대한 탐색 진행 
	for(int i = 0; i < 4; i++){
		dfs({nax, nay}, {nbx, nby}, cnt + 1, i);
	}
}

void solution() {
	for(int i = 0; i < 4; i++){
		dfs(coin[0], coin[1], 1, i);
	}

	if(answer > 10) answer = -1;
	cout << answer; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution();

	return 0; 
}