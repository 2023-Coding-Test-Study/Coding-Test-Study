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

int N, Q;
vector<int> lv;
vector<int> cnt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	lv.resize(N, 0);
	cnt.resize(N, 0);

	for(int i = 0; i < N; i++) {
		cin >> lv[i];
		if(i == 0) continue;

		// 이제까지 난이도가 감소한 횟수 누적해서 저장 
		if(lv[i - 1] > lv[i]) {
			cnt[i] = cnt[i - 1] + 1;
		}else{
			cnt[i] = cnt[i - 1];
		}
	}

	cin >> Q; 
	while(Q--) {
		int s, e; 
		cin >> s >> e;
		cout << cnt[e - 1] - cnt[s - 1] << '\n'; 
	}
	
	return 0;
}