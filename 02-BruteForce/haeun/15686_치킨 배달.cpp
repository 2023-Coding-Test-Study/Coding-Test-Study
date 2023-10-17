#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef pair<int, int> pii;

int N, M;
const int N_MAX = 51; 
const int M_MAX = 14; 

bool selected[M_MAX]; // 백트래킹에 사용 
int arr[M_MAX]; // 선택된 치킨집의 인덱스

int city[N_MAX][N_MAX]; // 도시의 정보 
vector<pii> houses; // 집의 좌표 
vector<pii> stores; // 치킨집의 좌표 
int answer = 1e9; 

void calcChickenDistanceOfCity() {
	int cityDist = 0; // 도시의 치킨 거리 

	for(int i = 0; i < houses.size(); i++) {
		// 현재 집에 대한 치킨 거리 
		// 현재 집을 중심으로 가장 가까운 치킨 집까지의 거리 
		int minDist = 1e9; 
		int r1 = houses[i].first; 
		int c1 = houses[i].second; 
		
		for(int j = 0; j < M; j++){ 
			int selectedIndex = arr[j]; 
			int r2 = stores[selectedIndex].first; 
			int c2 = stores[selectedIndex].second; 

			int curDist = abs(r1 - r2) + abs(c1 - c2);
			minDist = min(minDist, curDist); 
		}

		cityDist += minDist; 
	}

	answer = min(answer, cityDist); 
}

void dfs(int idx, int cnt){
	if(cnt == M){
		// 선택된 M개의 치킨집에 대해 
		// 도시의 치킨 거리의 최솟값 구하기 
		calcChickenDistanceOfCity(); 
		return; 
	}

	for(int i = idx; i < stores.size(); i++){
		if(!selected[i]){
			selected[i] = true; 

			// cnt번째로 선택된 치킨집의 인덱스 저장 
			arr[cnt] = i; 

			// 그 다음 원소 선택을 위해 재귀호출 
			dfs(i + 1, cnt + 1);

			selected[i] = false; 
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> N >> M; 

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> city[i][j];

			if(city[i][j] == 1){ 
				houses.push_back({i, j});
			}
			
			if(city[i][j] == 2){
				stores.push_back({i, j});
			}
		}
	}

	// 현재 존재하는 치킨집에서 M개 선택 
	dfs(0, 0); 

	cout << answer << "\n"; 

	return 0;
}