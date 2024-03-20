#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long k{ 0 };
	long long n{ 0 };
	long long end{ 0 };

	cin >> k >> n;

	long long* length = new long long[k];

	for (int i = 0; i < k; i++)
	{
		cin >> length[i];
		if (end < length[i])
			end = length[i];
	}

	long long left{ 1 };
	long long size{ 0 };

	while (left <= end)
	{
		long long count{ 0 }; // n에 가까워지는 값
		long long middle = (left + end) / 2;

		for (int i = 0; i < k; i++)
			count += length[i] / middle;

		if (count >= n) {
			if (size < middle)
				size = middle;
			left = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}

	cout << size;
}