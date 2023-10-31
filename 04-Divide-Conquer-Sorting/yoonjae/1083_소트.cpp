
#include <iostream>
#include <vector>
using namespace std;

int S;

void Sort(vector<int> &v)
{
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		int max = v[i];
		int maxIndex = i;

		for (int j = i+1; j < size; j++)
		{
			if (v[j] > max)
			{
				if (S >= j - i)
				{
					max = v[j];
					maxIndex = j;
				}
			}
		}

		for (int index = maxIndex; index > i; index--)
		{
			swap(v[index], v[index - 1]);
			S--;
		}
		if (S <= 0)
		{
			break;
		}
		
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	vector<int> nums;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	cin >> S;

	Sort(nums);

	for (int i = 0; i < N; i++)
	{
		cout << nums[i] << ' ';
	}

}