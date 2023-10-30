
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;

void printStars(int size, int x, int y, bool flag)
{
	if (size == 1)
	{
		if (flag)
		{
			board[x][y] = '*';
			return;
		}
	}

	if (flag)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1)
				{
					printStars(size / 3, x + (size / 3) * i, y + (size / 3) * j, false);
				}
				else
				{
					printStars(size / 3, x + (size / 3) * i, y + (size / 3) * j, true);
				}
			}
				

		}
	}
	else
	{
		for (int i = x; i < x + size; i++)
		{
			for (int j = y; j < y + size; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
	

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		vector<char> v(N);
		board.push_back(v);
	}

	printStars(N, 0, 0, true);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j];
		}

		cout << '\n';
	}

}