#include <iostream>
#include <string> 
#include <algorithm>
#include <vector> 
#include <set> 
using namespace std;

bool isBlankPosition(int i, int j, int n) {
	return (i / (n/3)) % 3 == 1 && (j / (n/3)) % 3 == 1; 
}

void divide(int i, int j, int n){
	// 현재 탐색하고 있는 정사각형 크기가 1이면 
	// 더 이상 탐색할 공백 위치가 없으므로 * 출력 
	if(n == 1){
		cout << "*";
	}
	// (i, j)가 현재 탐색하고 있는 정사각형 크기의 
	// 가운데 위치라면 공백 출력 
	else if(isBlankPosition(i, j, n)){
		cout << " ";
	}
	// n 크기를 3분의 1로 줄여서 해당 정사각형 기준으로 
	// 가운데 위치한 좌표를 공백으로 출력 
	else{ 
		divide(i, j, n / 3); 
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			divide(i, j, n);
		}
		cout << "\n"; 
	}
	
	return 0;
}
