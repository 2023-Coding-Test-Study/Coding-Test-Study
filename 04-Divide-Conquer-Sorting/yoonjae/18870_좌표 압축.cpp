
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	vector<int> sorted(nums);
	
	sort(sorted.begin(), sorted.end());

	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for (int i = 0; i < N; i++)
	{
		int index = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();

		cout << index << ' ';
	}

}