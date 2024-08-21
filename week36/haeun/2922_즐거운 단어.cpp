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

string input;
vector<int> vowels = {'A', 'E', 'I', 'O', 'U'};

bool isVowel(char ch){
	return find(vowels.begin(), vowels.end(), ch) != vowels.end();
}

ll dfs(ll idx, ll ja, ll mo, bool containL){
	if(ja >= 3 || mo >= 3) return 0;
	if(idx == input.size()) return containL; // 0 또는 1 

	ll ans = 0;
	if(input[idx] == '_'){
		// L이 아닌 자음
		ans += dfs(idx + 1, ja + 1, 0, containL) * 20; 

		// 자음 L
		ans += dfs(idx + 1, ja + 1, 0, true);

		// 모음
		ans += dfs(idx + 1, 0, mo + 1, containL) * 5; 
	}else{
		if(isVowel(input[idx])){
			ans += dfs(idx + 1, 0, mo + 1, containL);
		}else{
			if(input[idx] == 'L'){
				ans += dfs(idx + 1, ja + 1, 0, true);
			}else{
				ans += dfs(idx + 1, ja + 1, 0, containL);
			}
		}
	}

	return ans;
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> input;

	cout << dfs(0, 0, 0, false);
	
	return 0;
}