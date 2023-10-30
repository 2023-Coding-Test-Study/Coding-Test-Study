
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> board;

void QuadTree(int size, int x, int y)
{
	
	if (size == 1)
	{
		cout << board[x][y];
		return;
	}
	bool zeroflag = true;
	bool oneflag = true;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{

			if (board[i][j])
			{
				zeroflag = false;
			}
			else
			{
				oneflag = false;
			}
		}
	}
	if (zeroflag)
	{
		cout << 0;
	}
	else if (oneflag)
	{
		cout << 1;
	}
	else
	{
		cout << "(";
		QuadTree(size / 2, x, y);
		QuadTree(size / 2, x, y + size / 2);
		QuadTree(size / 2, x + size / 2, y);
		QuadTree(size / 2, x + size / 2, y + size / 2);
		cout << ")";
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		vector<int> v;
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++)
		{
			v.push_back(tmp[j] - '0');
		}
		board.push_back(v);
	}
	
	QuadTree(N, 0, 0);
}