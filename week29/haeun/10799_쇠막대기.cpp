#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input; 
	cin >> input; 
	
	stack<char> st;
	int answer = 0;

	for(int i = 0; i < input.size(); i++){
		char ch = input[i];
		if(ch == '('){
			st.push(ch);
		}else{
			// 레이저인 경우 
			if(input[i - 1] == '('){
				st.pop(); // 레이저의 열린 괄호 제거 
				answer += st.size(); // 남은 열린 괄호의 개수 
			}else{
				// 그냥 닫힌 괄호인 경우 
				answer++;
				st.pop(); // 가장 최근에 들어간 괄호 제거 
			}
		}
	}

	cout << answer; 
	
	return 0;
}
