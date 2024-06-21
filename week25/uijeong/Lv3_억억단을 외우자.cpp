#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int d[5000001]; // 각 i의 약수의 개수 
int a[5000001]; // 등장횟수에 따른 배열
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    for (int i = 2; i <= e; i++) { // 약수 개수 count
        for (int j = 1; j <= e/i; j++) {
            d[i * j]++;
        }
    }

    int max_idx;
    int max_v = 0;
    for (int j = e; j > 0; j--) { 
        // 등장 횟수에 따라서 배열 정렬
        // 이때 내림차순으로 
        if (max_v <= d[j]) {
            max_idx = j;
            max_v = d[j];
        }

        a[j] = max_idx;
    }

    // 작은 수 찾기 
    for (int k = 0; k < starts.size(); k++) {
        answer.push_back(a[starts[k]]);
    }

    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	solution(8, {1,3,7});

	return 0;
}
