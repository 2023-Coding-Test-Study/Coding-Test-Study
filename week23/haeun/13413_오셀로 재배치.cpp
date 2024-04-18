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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n; 
		cin >> n; // 최대 10만

		string src, dst;
		cin >> src >> dst;

		int diff[] = {0, 0};
		for(int i = 0; i < n; i++){
			char a = src[i];
			char b = dst[i];
			
			if(a != b){
				if(a == 'W') diff[0]++; 
				else diff[1]++; 
			}
		}

		cout << max(diff[0], diff[1]) << "\n";
	}

	return 0;
}