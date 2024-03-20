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

	// 오른쪽에서 왼쪽으로 이동 
	for(int i = N - 1; i >= 0; i--){
    	// 스택에 넣으려는 값(왼쪽)과 기존에 스택의 top에 있는 값(오른쪽) 비교 
		while(!st.empty() && st.top().second < height[i]){ 
        	// 새로운 값(왼쪽)이 더 크면 해당 탑의 번호 저장 
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