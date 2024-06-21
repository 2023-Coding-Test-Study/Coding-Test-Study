#include <iostream>

using namespace std;

int N;
long long d[1000001]; // N번째 감소하는 수 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N;

	if (N <= 10) { // 일의 자릿수인 경우 그냥 자기자신
		cout << N;
		return;
	}
	for (int i = 0; i < 10; i++) { 
		d[i] = i;
	}

	int th = 10; // 10번째 감소하는 수 부터 찾기 -> 이미 0~9번째 감소하는 수는 위에서 찾음
	for (int i = 1; i <= N; i++) {  
		for (int j = 0; j < d[i] % 10; j++) { // [i번째 감소하는 수(k 자릿수)] + [마지막 자릿수%10 개의 숫자] 
			d[th] = d[i] * 10 + j; // k+1 자릿수의 th번째 감소하는 수를 찾음! 
			th++;
		}
	}

	if (d[N] == 0) cout << -1;
	else cout << d[N];

	return 0;
}
