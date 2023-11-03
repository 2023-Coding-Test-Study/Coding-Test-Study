#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

const int MAX = 1000001; 
int a[MAX]; 
int b[MAX];
int N, M; 

void input() {
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		cin >> a[i]; 
	}

	for(int i = 0; i < M; i++){
		cin >> b[i]; 
	}
}

void solution() {
	int pa = 0, pb = 0; 

	while(pa < N && pb < M){
		if(a[pa] < b[pb]) {
			cout << a[pa++] << " ";
		}else{
			cout << b[pb++] << " ";
		}
	}

	while(pa < N){
		cout << a[pa++] << " ";
	}

	while(pb < M){
		cout << b[pb++] << " "; 
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