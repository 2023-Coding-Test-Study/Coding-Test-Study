#include <bits/stdc++.h>

using namespace std;

string s;
bool v[201]; // 최대길이가 200이기 때문
vector<pair<int, int>> e;
stack<int> st;
set<string> ans;// 중복되는 반례가 존재하기 때문 

void dfs(int idx, int del) {
	if (del >= 1) { // 한 번 이상 제거되었다면 출력하기  
		string temp = "";
		for (int i = 0; i < s.length(); i++) {
			if (!v[i]) {
				// 방문한 적이 없다면 
				temp += s[i];
			}
		}
		ans.insert(temp); // 추가, 이때 set이기 때문에 중복제거 및 오름차순 정렬이 자동으로 된다. 
	}

	for (int i = idx; i < e.size(); i++) {
		v[e[i].first] = true; // 출력 안 해도 됨 
		v[e[i].second] = true; // 출력 안 해도 됨 

		dfs(i + 1, del + 1); // 그 다음 제거 조합 출력 

		v[e[i].first] = false;
		v[e[i].second] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(i); //  ( 위치 추가
		}
		else if (s[i] == ')') {
			e.push_back({ st.top(), i }); // 제일 가까운 '(' 위치와 함께 ')' 위치 추가
			st.pop(); // 제거
		}
	}

	dfs(0, 0);
	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << *i << "\n"; // iterator는 주소값이므로 
	}
}
