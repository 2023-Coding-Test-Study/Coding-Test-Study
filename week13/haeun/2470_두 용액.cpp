#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll; 

int N; 
vector<int> arr;
ll minGap = 3e9; 
pii answer;

void input() {
	cin >> N; 

	for(int i = 0; i < N; i++){
		int num; 
		cin >> num; 
		arr.push_back(num);
	}
}

void solution() {
	sort(arr.begin(), arr.end());
	
	// 양끝에서 투포인터 범위를 좁히면서 합이 최대한 0에 가까운 경우를 찾는다. 
	int left = 0; 
	int right = arr.size() - 1; 

	while(left < right){
		ll sum = arr[left] + arr[right];

		// 합의 절댓값이 더 작은 것으로 정답 갱신 
		if(minGap > abs(sum)){ 
			minGap = abs(sum); 
			answer = {arr[left], arr[right]};
		}

		if (sum > 0) right--; // 합을 줄인다. 
		else if (sum < 0) left++; // 합을 키운다. 
		else break; 
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution();
	cout << answer.first << " " << answer.second;

	return 0;
}
