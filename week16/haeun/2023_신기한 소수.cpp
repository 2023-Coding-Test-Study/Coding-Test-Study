#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map> 
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

int N;
int prime[4] = {2, 3, 5, 7};

void input() {
	cin >> N; // 자리 수 
}

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void dfs(int num, int digit) {
	if (digit == 0)
		cout << num << "\n";
	
	for(int i = 1; i < 10; i += 2){
		int temp = num * 10 + i;
		if(isPrime(temp)){
			dfs(temp, digit - 1);
		}
	}
}

void solution() {
	for(int i = 0; i < 4; i++){
		dfs(prime[i], N - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 

	return 0; 
}
