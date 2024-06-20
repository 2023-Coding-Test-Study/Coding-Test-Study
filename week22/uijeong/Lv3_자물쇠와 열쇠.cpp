#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M; // lock의 size, key의 size
int newS; // 새로운 사이즈 
vector<vector<int>> map; // 새로운 지도
int isValid; // 홈 부분의 개수 파악

int valid(int sx, int sy, vector<vector<int>> key) {
	int x = 0;
	int y = 0;
	int check = 0;
	for (int i = sx; i < sx + M; i++, x++) {
		for (int j = sy; j < sy + M; j++, y++) {
			if (map[i][j] == 1 && key[x][y] == 1) return -1;
			if (map[i][j] == 0 && key[x][y] == 0) return -1;
			if (map[i][j] == 0 && key[x][y] == 1) check++;
		}
		y++;
	}
	return check;
}

void rotate(vector<vector<int>>& Key)
{
	vector<vector<int>> Temp  = Key;
	for (int i  = 0; i  < M; i++)
	{
		for (int j  = 0; j  < M; j++)
		{
			Temp[i][j] = Key[M  - 1 - j][i];
		}
	}
	Key  = Temp;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	N = key.size();
	M = lock.size();

	newS = N + 2 * (M - 1);
	map.resize(newS, vector<int>(newS, 2)); // 2로 초기화 

	int x = 0;
	int y = 0;
	for (int i = M - 1; i < newS - (M - 1); i++, x++) {
		for (int j = M - 1; j < newS - (M - 1); j++, y++) {
			map[i][j] = lock[x][y];
			if (map[i][j] == 0) isValid++;
		}
	}

	for (int r = 0; r < 4; r++) {
		for (int i = 0; i < M+N-1; i++) {
			for (int j = 0; j < M+N-1; j++) {
				int result = valid(i, j, key);
				if (result == isValid) return true;
			}
		}
		rotate(key);
	}

	return answer;
}

int main(void) {
	cout << solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1},{1, 1, 0},{1, 0, 1} });
}
