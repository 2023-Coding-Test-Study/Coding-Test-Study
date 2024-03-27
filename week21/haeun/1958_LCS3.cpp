#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll; 
typedef pair<int, int> pii;

const int MAX = 101; 
int dp[MAX][MAX][MAX];

int max(int a, int b, int c){
	return max(max(a, b), c);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c; 

	a = ' ' + a; 
	b = ' ' + b; 
	c = ' ' + c;

	for(int i = 1; i < a.size(); i++){
		for(int j = 1; j < b.size(); j++){
			for(int k = 1; k < c.size(); k++){
				// 3개의 문자가 모두 같은 경우 
				if(a[i] == b[j] && b[j] == c[k]){
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1; 
				}else{ 
					// 이전 과정까지의 최장 공통 부분 수열 길이 저장 
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
				}
			}
		}
	}

	cout << dp[a.size() - 1][b.size() - 1][c.size() - 1]; 
		
	return 0;
}
