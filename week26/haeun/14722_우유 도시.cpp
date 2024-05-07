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

const int MAX = 1001; 
int milk[MAX][MAX]; 
int dp[3][MAX][MAX];
int N;

// 이전 방향: 0(왼쪽), 1(위쪽) 
int dx[] = {0, -1};
int dy[] = {-1, 0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; 

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> milk[i][j];

			if(milk[i][j] == 0) {
				dp[0][i][j] = 1;
			}
		}
	}

	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			for(int d = 0; d < 2; d++){
				int px = x + dx[d]; // 이전 x 
				int py = y + dy[d]; // 이전 y
                
				if(px < 0 || px >= N || py < 0 || py >= N) continue;

				int curMilk = milk[x][y];
				int prevMilk = (curMilk + 2) % 3; 

				// 우유를 마실 수 없는 경우 
				dp[0][x][y] = max(dp[0][x][y], dp[0][px][py]);
				dp[1][x][y] = max(dp[1][x][y], dp[1][px][py]);
				dp[2][x][y] = max(dp[2][x][y], dp[2][px][py]);

				// 우유를 마실 수 있는 경우 
				if(dp[prevMilk][px][py] > 0) {
					dp[curMilk][x][y] =
						max(dp[curMilk][x][y], dp[prevMilk][px][py] + 1);
				}
			}
		}
	}

	int ans = max(max(dp[0][N - 1][N - 1], dp[1][N - 1][N - 1]), dp[2][N - 1][N - 1]);
	cout << ans; 
	
	return 0;
}