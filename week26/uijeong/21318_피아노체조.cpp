#include <vector>
#include <iostream>
using namespace std;

int d[100000];
int N, Q;
int ans = 0;
vector<int> pro;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		cin >> temp;
		pro.push_back(temp);
	} // 입력 받기 

	for (int k = 1; k < N; k++) {
		d[k] += d[k - 1]; // 이전의 결과를 누적  
		if (pro[k] < pro[k - 1]) {
			// 이전 난이도가 더 높다면? 
			d[k] += 1; // 현재 결과를 누적 
		}
	}
	cin >> Q;
	for (int j = 0; j < Q; j++) {
		int x, y;
		cin >> x >> y;
		cout << d[y-1] - d[x-1] << "\n"; // 즉 d[y] - d[x]가 x부터 y까지 실수한 악보 개수
	}

	return 0;
}
