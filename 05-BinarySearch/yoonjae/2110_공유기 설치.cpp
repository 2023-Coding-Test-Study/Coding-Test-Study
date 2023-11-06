#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N{ 0 };
	int C{ 0 };
	int cnt{ 0 };
	int res{ 0 };
	
	cin >> N >> C;

	int* loc = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> loc[i];
	}

	sort(loc, loc + N);
	int start = 1;
	int end = loc[N-1] - loc[0];

	while (start <= end)
	{
		cnt = 1;
		int middle = (start + end) / 2;
		int flag = loc[0];

		for (int i = 1; i < N; i++)
		{
			if (loc[i] - flag >= middle)
			{
				cnt++;
				flag = loc[i];
			}
		}

		if (cnt >= C)
		{
			if (middle > res)
			{
				res = middle;
			}
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}

	}

	cout << res;
}