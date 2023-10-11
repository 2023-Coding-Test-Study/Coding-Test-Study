#include <iostream>
#include <string>
#include <stack> 
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int cnt = 0;
	int N; 
	cin >> N;

	while(N--){
		string word; 
		cin >> word; 

		stack<char> st;
		for(auto ch: word){
			if(st.empty()){
				st.push(ch);
				continue; 
			}

			if(st.top() == ch){
				st.pop(); 
			}else{
				st.push(ch);
			}
		}

		if(st.empty()) {
			cnt++;
		}
	}

	cout << cnt; 
	
	return 0;
}