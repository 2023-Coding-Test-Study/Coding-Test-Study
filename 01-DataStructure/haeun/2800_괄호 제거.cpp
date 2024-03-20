#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <stack> 
#include <set>
using namespace std;

const int MAX = 201; 
bool removed[MAX]; // 괄호 쌍의 삭제 여부  
vector<pair<int, int>> paren; // 괄호 쌍의 인덱스 
stack<int> st; 
set<string> answer; // 중복 제거 & 오름차순 정렬 
string input; 

// 입력 문자열에서 괄호 쌍의 인덱스를 벡터에 저장한다.
void saveParenthesesIndex() {
	for(int i = 0; i < input.size(); i++){
		if(input[i] == '(') {
			st.push(i);
			continue; 
		}
	
		if(input[i] == ')') {
			paren.push_back({st.top(), i});
			st.pop();
		}
	}
}

void dfs(int idx, int removedCount) {
    // 1개 이상의 괄호 쌍을 삭제한 문자열 저장 
	if(removedCount >= 1) {
		string temp = "";
		for(int i = 0; i < input.size(); i++){ 
			if(!removed[i]) temp += input[i]; 
		}

        // 중복 제거 & 오름차순 정렬 
		answer.insert(temp); 
	}

	for(int i = idx; i < paren.size(); i++) { // idx부터 시작 
        // 상태 변화 
		removed[paren[i].first] = true; 
		removed[paren[i].second] = true; 
		
        // 재귀 호출 
		dfs(i + 1, removedCount + 1);
		
        // 상태 복구 
		removed[paren[i].first] = false; 
		removed[paren[i].second] = false; 
	}
}

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> input; 

	saveParenthesesIndex();

	dfs(0, 0);

	for(auto str: answer){
		cout << str << "\n"; 
	}
	
	return 0;
}