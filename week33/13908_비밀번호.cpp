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

const int MAX = 10;
int N, M;
vector<int> contain; // 반드시 포함해야 하는 수
vector<int> v; // 선택된 숫자 저장
int ans = 0;

bool linearSearch(int key){
	return find(v.begin(), v.end(), key) != v.end();
}

bool checkPassword(){
	for(int i = 0; i < contain.size(); i++){ // O(M)
		if(!linearSearch(contain[i])){ // O(N)
			return false;
		}
	}

	return true;
}

// 중복을 허용하므로 selected 배열은 따로 필요 X 
void dfs(int cnt){
	if(cnt == N){
		// 배열 v에 M개의 숫자가 모두 포함되어 있는지 확인 
		if(checkPassword()) {
			ans++;
		}
		return;
	}

	// 순열이므로 인덱스 0부터 시작 
	for(int i = 0; i < MAX; i++){
		v.push_back(i);
		dfs(cnt + 1);
		v.pop_back();
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i = 0; i < M; i++){
		int num; 
		cin >> num;
		contain.push_back(num);
	}

	dfs(0);

	cout << ans;
	
	return 0;
}