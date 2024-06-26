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

int N;
int minCnt = 1e9, maxCnt = -1;

bool isOdd(int x){
	return x % 2 == 1;
}

int calcOddNum(string s){
	int cnt = 0; 
	for(int i = 0; i < s.size(); i++){
		if(isOdd(s[i] - '0')) cnt++;
	}
	return cnt++;
}

void dfs(string now, int cnt){
	int digit = now.size();
	
	if(digit == 1){
		cnt += calcOddNum(now);

		// 홀수의 최소, 최대 개수 갱신 
		maxCnt = max(maxCnt, cnt);
		minCnt = min(minCnt, cnt);
		
		return;
	}

	if(digit == 2){
		cnt += calcOddNum(now);
		int sum = (now[0] - '0') + (now[1] - '0');
		dfs(to_string(sum), cnt);
	}else{
		cnt += calcOddNum(now);
		
		for(int i = 1; i < digit - 1; i++){
			string s1, s2, s3;
			for(int j = i + 1; j < digit; j++){
				s1 = now.substr(0, i);
				s2 = now.substr(i, j - i);
				s3 = now.substr(j);
				int sum = stoi(s1) + stoi(s2) + stoi(s3);
				dfs(to_string(sum), cnt);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N; 
	cin >> N;
	
	dfs(N, 0);
	cout << minCnt << " " << maxCnt;

	return 0;
}
