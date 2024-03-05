#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

int N; 
bool isFinish = false; 
string answer = "";

void input(){
	cin >> N; 
}

bool isBadSeq(string str) {
	int len = str.size();
	
	for(int i = 1; i <= len / 2; i++){
		string rear = str.substr(len - i, i); 
		string front = str.substr(len - 2 * i, i); 
		if(rear == front) return true;
	}

	return false; 
}

void dfs(string result, int cnt){
	// 좋은 수열 중에서 최솟값을 구한 경우, 종료 
	if(isFinish) return;

	// 나쁜 수열인 경우, 다른 경우의 수로 넘어감. 
	if(isBadSeq(result)) return;

	// 좋은 수열 발견 (첫번째 경우만 저장하면 된다.)
	if(cnt == N){
		answer = result;
		isFinish = true;
		return;
	}

	// 1, 2, 3으로 이루어진 N자리 정수 만들기 
	dfs(result + '1', cnt + 1);
	dfs(result + '2', cnt + 1);
	dfs(result + '3', cnt + 1);
}

void solution() {
	dfs("", 0);
	cout << answer; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 

	return 0; 
}
