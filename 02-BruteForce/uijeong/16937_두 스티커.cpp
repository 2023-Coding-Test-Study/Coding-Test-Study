#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, W, N;
	pair<int, int> arr[100];

	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	int sum = 0;
	int answer = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			sum = (arr[i].first * arr[i].second) + (arr[j].first * arr[j].second);
				if (sum > H * W) { // 넓이가 더 큰 경우 
					continue;
				}
				else {
					if (arr[i].first >= H && arr[i].second >= W && arr[j].first >= H && arr[j].second >= W) { // 길이를 충족시킨다면
						if (arr[i].first + arr[j].first <= H || arr[i].first + arr[j].second <= H || arr[i].second + arr[j].first <= H || arr[i].second + arr[j].second <= H) {
							// 하나라도 들어갈 수 있다면 
							if (answer <= sum) {
								answer = sum;
								continue;
							}
						}

						if (arr[i].first + arr[j].first <= W || arr[i].first + arr[j].second <= W || arr[i].second + arr[j].first <= W || arr[i].second + arr[j].second <= W) {
							// 하나라도 들어갈 수 있다면 
							if (answer <= sum) {
								answer = sum;
								continue;
							}
						}
					}
				}
		}
	}

	cout << answer;
}
