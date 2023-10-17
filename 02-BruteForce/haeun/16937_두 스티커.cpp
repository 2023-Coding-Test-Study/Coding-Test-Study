#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <stack> 
#include <queue> 
#include <set>
using namespace std;
typedef pair<int, int> pii; 

const int MAX = 101; 
int H, W, N;
vector<pair<pii, int>> sticker; // 회전한 모양까지 포함하여 저장 
bool selected[MAX]; // 백트래킹에 사용 
int arr[2]; // 선택된 2개의 스티커 인덱스 저장 
int answer = 0; 

void checkTwoStickerSize() {
	int firstH = sticker[arr[0]].first.first; 
	int firstW = sticker[arr[0]].first.second; 
	int firstArea = firstH * firstW;

	int secondH = sticker[arr[1]].first.first; 
	int secondW = sticker[arr[1]].first.second; 
	int secondArea = secondH * secondW; 

	if(firstH + secondH <= H && max(firstW, secondW) <= W){ 
		answer = max(answer, firstArea + secondArea); 
	}

	if(firstW + secondW <= W && max(firstH, secondH) <= H){ 
		answer = max(answer, firstArea + secondArea); 	
	}
}

void dfs(int idx, int cnt){
	// 2개를 선택한 경우에 대한 처리 
	if(cnt == 2){
		checkTwoStickerSize();
		return; 
	}

	// 조합이므로 i는 idx부터 시작함. (한번 선택한 원소는 돌아보지 않음.) 
	for(int i = idx; i < sticker.size(); i++){
		int height = sticker[i].first.first; 
		int width = sticker[i].first.second; 
		int num = sticker[i].second; 

		if(!selected[num]){
			// 상태 변화
			selected[num] = true; 

			// cnt번째로 선택된 스티커 인덱스 저장 
			arr[cnt] = i; 

			// 재귀 호출 
			dfs(i + 1, cnt + 1); 

			// 상태 복구
			selected[num] = false; 
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);
	 
	cin >> H >> W >> N;

	for(int i = 0; i < N; i++){
		int r, c; 
		cin >> r >> c; 
		
		sticker.push_back({{r, c}, i});
		
		if(r != c){
			sticker.push_back({{c, r}, i});
		}
	}

	dfs(0, 0);

	cout << answer; 

	return 0;
}