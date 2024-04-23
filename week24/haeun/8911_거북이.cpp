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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; 
	cin >> t;

	while(t--){
		string cmd; 
		cin >> cmd; 

		pair<pii, int> turtle = {{0, 0}, 0}; // 위치, 방향 
		int x = turtle.first.first; 
		int y = turtle.first.second; 
		int dir = turtle.second;

		int minX = 0, maxX = 0;
		int minY = 0, maxY = 0; 

		for(auto ele: cmd){
			switch(ele){
				case 'F': {
					// 방향 그대로, 앞으로 한칸
					x += dx[dir];
					y += dy[dir];
					break;
				}
				case 'B': {
					// 방향 그대로, 뒤로 한칸
					int idx = (dir + 2) % 4;
					x += dx[idx];
					y += dy[idx];
					break; 
				}
				case 'L': 
					// 위치 그대로, 왼쪽으로 90도 회전 
					dir = (dir + 1) % 4;  
					break; 
				case 'R':
					// 위치 그대로, 오른쪽으로 90도 회전 
					dir = (dir + 3) % 4; 
					break;
			}

            // 최소, 최대 좌표 갱신 
			minX = min(x, minX);
			maxX = max(x, maxX);
			minY = min(y, minY);
			maxY = max(y, maxY);
		}

		cout << (maxX - minX) * (maxY - minY) << "\n";
	}

	return 0;
}