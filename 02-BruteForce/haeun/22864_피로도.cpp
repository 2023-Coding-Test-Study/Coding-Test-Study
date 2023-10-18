#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <stack> 
#include <queue> 
#include <set>
using namespace std;

const int HOUR = 24; 

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int A, B, C, M; 
	cin >> A >> B >> C >> M; 

	int fatigue = 0;  // 피로도 
	int workTime = 0; // 업무 시간 
	
	for(int i = 0; i < HOUR; i++){ 
		if(A > M) break;
		if(fatigue + A <= M){ 
			fatigue += A; 
			workTime++; 
		}else{ 
			fatigue -= C; 
			if(fatigue < 0) fatigue = 0; 
		}
	}

	int totalWorkload = workTime * B; 
	cout << totalWorkload << "\n"; 
	
	return 0;
}
