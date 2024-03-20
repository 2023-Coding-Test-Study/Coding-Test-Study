
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A_size, B_size;
	queue<int> A;
	queue<int> B;

	cin >> A_size >> B_size;

	for (int i = 0; i < A_size; i++)
	{
		int tmp;
		cin >> tmp;
		A.push(tmp);
	}

	for (int i = 0; i < B_size; i++)
	{
		int tmp;
		cin >> tmp;
		B.push(tmp);
	}

	for (int i = 0; i < A_size + B_size; i++)
	{
		if (A.empty())
		{
			if (!(B.empty()))
			{
				cout << B.front();
				B.pop();
				cout << ' ';
				continue;
			}
		}

		if (B.empty())
		{
			if (!(A.empty()))
			{
				cout << A.front();
				A.pop();
				cout << ' ';
				continue;
			}
		}


		if (A.front() < B.front())
		{
			cout << A.front();
			A.pop();
		}
		else
		{
			cout << B.front();
			B.pop();
		}

		cout << ' ';
	}
}