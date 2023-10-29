#include <iostream>
#include <string> 
using namespace std;

const int MAX = 64;
int arr[MAX][MAX];

void divide(int n, int r, int c){	
	// 현재 영역의 시작점 위치 저장 
	int cur = arr[r][c];

	// 현재 영역이 모두 0 또는 1로 이루어져 있는지 확인 
	for(int i = r; i < r + n; i++){ 
		for(int j = c; j < c + n; j++){
			// 다른 숫자가 발견되면, 영역의 크기를 절반으로 줄이고
			// 각 영역의 시작점 좌표도 갱신한다. 
			if(cur != arr[i][j]){
				cout << "(";
				divide(n / 2, r, c);
				divide(n / 2, r, c + n / 2);
				divide(n / 2, r + n / 2, c);
				divide(n / 2, r + n / 2, c + n / 2);
				cout << ")"; 
				return; 
			}
		}
	}

	// 모두 0이거나 1이면 그대로 출력 
	cout << cur; 
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s; 

		// 길이가 n인 문자열의 문자 하나하나를 정수로 변환해서 저장 
		for(int j = 0; j < n; j++){
			arr[i][j] = s[j] - '0'; 
		}
	}

	divide(n, 0, 0); 

	return 0;
}