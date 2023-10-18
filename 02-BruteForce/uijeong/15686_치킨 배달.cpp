#include <bits/stdc++.h>

using namespace std;

int city[51][51];
vector<pair<int, int>> chick;
vector<pair<int, int>> home;
vector<int> sc; // 선택한 치킨집
int N, M;
int ans = 10000000; // 최종 답

void distance() {
	// 집을 기준으로 치킨집 거리 계산 
	int cd = 0;

	for (int i = 0; i < home.size(); i++) { // 각 집에 대해서
		int hd = 1000000;
		int d = 0;

		int x1 = home[i].first;
		int y1 = home[i].second;

		for (int j = 0; j < sc.size(); j++) { // 최소 거리 계산
			int x2 = chick[sc[j]].first;
			int y2 = chick[sc[j]].second;

			d = abs(x1 - x2) + abs(y1 - y2);
			hd = min(hd, d);
		}
		cd += hd; // 도시 거리 합
	}

	ans = min(cd, ans); // 도시의 최소 거리 구하기 
}

void selectChick(int cnt, int start) { // 개수와 시작점
	if (cnt == M) { 
		// M개 모두 선택했을 때 거리 계산 
		distance();
		return;
	}

	for (int i = start; i < chick.size(); i++) { // 조합이므로 중복되면 안 되니까 시작점은 start!
		sc.push_back(i); // 선택
		selectChick(cnt + 1, i + 1);
		sc.pop_back(); 
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) { // 치킨 집 정보 추가
				chick.push_back({ i, j });
			}

			if (city[i][j] == 1) { // 집 정보 추가
				home.push_back({ i, j });
			}
		}
	}

	selectChick(0, 0);

	cout << ans;

}
