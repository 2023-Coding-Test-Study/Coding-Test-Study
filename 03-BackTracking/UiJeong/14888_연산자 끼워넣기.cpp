#include <bits/stdc++.h>

using namespace std;

int n[12];
int N;
int o[4]; // 연산자 배열
vector<int> v;
int Max = -1e9;
int Min = 1e9;

void result(){
	int temp = n[0]; // 초기값

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) { // + 인 경우
			temp += n[i + 1];
		}
		else if (v[i] == 1) { // - 인 경우
			temp -= n[i + 1];
		}
		else if (v[i] == 2) { // *인 경우
			temp *= n[i + 1];
		}
		else { // 나누기 인 경우 
			if (temp < 0) {
				temp = (int)((-temp) / n[i + 1]);
				temp = -temp;
			}
			else {
				temp = (int)(temp / n[i + 1]);
			}
		}
	}

	if (Max < temp) Max = temp;
	if (Min > temp) Min = temp;
}

void dfs(int cnt) {  
	if (cnt == N-1) { // N-1개까지 선택하는데 성공 
		result();
		return;
	}


	for (int i = 0; i < 4; i++) { // 4가지 경우의 수 
		if (o[i] > 0) {
			// 해당 연산자가 존재하는 경우에 
			v.push_back(i); // 해당 연산 선택
			o[i]--; // 방문 체크라 생각하면 됨
			dfs(cnt + 1);
			v.pop_back(); // 연산 선택 제거 - 백 트래킹
			o[i]++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		// 숫자 
		cin >> n[i];
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> o[i];
	}

	dfs(0);
	cout << Max << "\n" << Min;
}
