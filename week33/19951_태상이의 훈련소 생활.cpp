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

const int MAX = 100001;
int N, M;
int arr[MAX];

struct cmd {
	int aidx;
	int bidx;
	int k;
};
vector<cmd> commands;

void input(){
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < M; i++){
		int a, b, k;
		cin >> a >> b >> k;
		commands.push_back({a - 1, b - 1, k});
	}
}

void solution(){
	vector<int> sum(N, 0);
	for(int i = 0; i < M; i++){
		int start = commands[i].aidx;
		int end = commands[i].bidx;
		int k = commands[i].k;
		
		sum[start] += k;
		if(end < N - 1)	sum[end + 1] -= k;
	}

	for(int i = 0; i < N - 1; i++){
		sum[i + 1] += sum[i];
	}

	for(int i = 0; i < N; i++){
		arr[i] += sum[i];
	}

	for(int i = 0; i < N; i++){
		cout << arr[i] << " ";
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution();

	return 0;
}