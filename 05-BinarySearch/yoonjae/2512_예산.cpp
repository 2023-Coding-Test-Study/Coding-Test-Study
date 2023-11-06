#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n{ 0 };
	int M{ 0 };
	int all{ 0 };
	int max{ 0 };

	cin >> n;

	int* budget = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> budget[i];
		all += budget[i];
		if (max < budget[i])
		{
			max = budget[i];
		}
	}

	cin >> M;

	int right{ M };
	int start{ 0 };
	int amount{ 0 };

	if (all <= M)
	{
		cout << max;
	}
	else
	{
		while (start <= right)
		{
			int sum{ 0 };
			int middle = (start + right) / 2;

			for (int i = 0; i < n; i++)
			{
				if (middle > budget[i])
				{
					sum += budget[i];
				}
				else
				{
					sum += middle;
				}
			}

			if (sum > M)
			{
				right = middle - 1;
			}
			else
			{
				if (amount < middle)
				{
					amount = middle;
				}

				start = middle + 1;

			}

		}

		cout <<  amount;
	}


	
}