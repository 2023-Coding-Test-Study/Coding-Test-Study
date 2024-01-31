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

int one, two, three, four, five, six;

void input() {
	cin >> one >> two >> three >> four >> five >> six; 
}

void solution() {
	int answer = six;
	
	while(one != 0 || two != 0 || three != 0 || four != 0 || five != 0) {
		while(five > 0){
			int cnt = 36;

			// 크기가 5인 색종이 하나 붙이기 
			five--; 
			cnt -= 25; 

			// 크기가 1인 색종이의 개수 <= 남은 영역 크기 
			if(one <= cnt){
				// 크기가 1인 색종이 모두 붙이기 
				one = 0;
			}else{
				// 크기가 1인 색종이의 개수 갱신 
				one -= cnt;
			}

			answer++; 
		}

		while(four > 0){
			int cnt = 36; 

			// 크기가 4인 색종이 하나 붙이기 
			four--; 
			cnt -= 16; 

			if(two >= 5){
				// 크기가 2인 색종이 5개 붙이기 
				two -= 5; 
				cnt -= 20; 
			}else{
				// 크기가 2인 색종이 모두 붙이기 
				cnt -= two * 4; 
				two = 0; 
			}

			// 크기가 1인 색종이 붙이기 
			if(one <= cnt){
				one = 0; 
			}else{
				one -= cnt; 
			}

			answer++; 
		}

		while(three > 0){
			int cnt = 36; 
			
			if(three >= 4){
				// 크기가 3인 색종이 4개 붙이기 
				three -= 4; 
				cnt = 0;
			}else{
				// 크기가 3인 색종이 모두 붙이기 
				cnt -= three * 9; 
				three = 0; 
			}

			if(cnt == 27){
				if(two >= 5){
					two -= 5;
					cnt -= 20;
				}else{
					cnt -= two * 4;
					two = 0;
				}
			}

			if(cnt == 18){
				if(two >= 3){
					two -= 3; 
					cnt -= 12; 
				}else{
					cnt -= two * 4; 
					two = 0; 
				}
			}

			if(cnt == 9 && two >= 1){
				cnt -= two * 4; 
				two = 0; 
			}

			if(one <= cnt){
				one = 0; 
			}else{
				one -= cnt; 
			}

			answer++; 
		}

		while(two > 0){
			int cnt = 36;

			if(two >= 9){
				two -= 9; 
				cnt = 0; 
			}else{
				cnt -= two * 4; 
				two = 0; 
			}

			if(one <= cnt){
				one = 0; 
			}else{
				one -= cnt; 
			}

			answer++; 
		}

		while(one > 0){
			if(one >= 36){
				one -= 36; 
			}else{
				one = 0; 
			}

			answer++; 
		}
	}

	cout << answer << endl; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution(); 

	return 0; 
}
