#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <stack> 
#include <set>
using namespace std;

const int MAX = 500001;
int height[MAX];
int answer[MAX]; 

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int N; 
	cin >> N; 

	for(int i = 0; i < N; i++){
		cin >> height[i];
	}
	
	stack<pair<int, int>> st;

	// 오른쪽에서부터 시작 
	for(int i = N - 1; i >= 0; i--){
		// 현재 탑보다 높이가 작은 탑이 모두 나올 때까지 pop (스택이 빌 때까지)
		while(!st.empty() && st.top().second < height[i]){
			answer[st.top().first] = i + 1; 
			st.pop(); 
		}

		st.push({i, height[i]});
	}

	for(int i = 0; i < N; i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}