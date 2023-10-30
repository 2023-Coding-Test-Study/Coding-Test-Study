#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<int> v;
	vector<int> cv;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		cv.push_back(temp);
	}

	sort(cv.begin(), cv.end()); // 정렬, 오름차순
	cv.erase(unique(cv.begin(), cv.end()), cv.end()); // 중복값의 위치~ 끝까지 삭제

	for (int i = 0; i < N; i++) {
		cout << lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin() << " "; // 원하는 값의 정렬 배열에서의 인덱스 값이 좌표 압축값 
	}
}
