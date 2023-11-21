#include <string>
#include <vector>
#include <set> 
#include <cmath> 
#include <iostream> 
using namespace std;

const int MAX = 8; 

// N을 cnt번 연속으로 이어붙인 수 반환  
int calcCotinuousNumber(int N, int cnt) {
	int num = 0; 

	while(cnt > 0){
		num += N * pow(10, cnt - 1); 
		cnt--; 
	}

	return num; 
}

int solution(int N, int number) {
	if(N == number) return 1; 

	int answer = -1; 

	// 집합 배열 
	vector<set<int>> s(MAX);

	// N을 i번 연속으로 이어붙인 수 구하기 
	int i = 1; 
	for(auto& si: s){
		si.insert(calcCotinuousNumber(N, i));
		i++; 
	}

	for(int i = 1; i < MAX; i++){
		for(int j = 0; j < i; j++){
			// N을 j번 사용해서 나오는 수들의 집합 
			for(auto& a: s[j]){
				//  N을 (i-j-1)번 사용해서 나오는 수들의 집합 
				for(auto& b: s[i-j-1]){ 
					s[i].insert(a + b);
					s[i].insert(a - b);
					s[i].insert(a * b);
                    
                    // 0으로 나누는 경우 예외 처리!! 
					if(b != 0) s[i].insert(a / b);
				}
			}
		}

		// 집합에서 number가 발견되면, i의 최솟값 반환 
		if(s[i].find(number) != s[i].end()){
			answer = i + 1;
			break; 
		}
	}
	
	return answer;
}