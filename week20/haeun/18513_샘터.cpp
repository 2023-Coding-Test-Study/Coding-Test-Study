#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll; 
typedef pair<int, int> pii; 

const int N_MAX = 100000;
int N, K; 
map<int, bool> visited;
queue<int> q;
int dx[] = { 1, -1 };

void input() {
	cin >> N >> K;

	for(int i = 0; i < N; i++){
		int x; 
		cin >> x; 
		q.push(x); // 샘터의 위치 저장 
		visited[x] = true; // 방문 처리 
	}
}

ll solution() {
	int dist = 1;
	ll sum = 0;

	while(!q.empty()){
    	// 아래 for문에서 pop 연산에 의해 크기가 줄어들기 때문에 초기값 저장 
		int currentQ = q.size(); 

		for(int i = 0; i < currentQ; i++){
			int x = q.front(); 
			q.pop();
			
            // 샘터로부터 ± dist 좌표의 방문 여부 확인 
			for(int j = 0; j < 2; j++){
				int nx = x + dx[j];
				
				if(!visited[nx]){
					visited[nx] = true; 
					q.push(nx);
					
					sum += dist; // 거리합 갱신 
					K--; // 집 설치 
					
                    // 집을 모두 설치한 경우 정답 리턴 
					if(K == 0) return sum; 
				}
			}
		}

		dist++;
	}

	return sum; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	cout << solution(); 
	
	return 0;
}