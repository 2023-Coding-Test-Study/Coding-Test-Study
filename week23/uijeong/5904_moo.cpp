#include<bits/stdc++.h>

using namespace std;

int N;
vector<long long> s; // 크기를 담는 배열 
int k = 0; // k번째

char find_m(int k) {
	if (k == 0) {
		// 종료 조건
		if (N == 1) return 'm';
		else return 'o';
	}

	long long mid_l = s[k - 1]+1; // 가운데 부분 시작 index
	long long mid_r = s[k - 1] + k + 3; // 가운데 부분 끝 index
	if (N < mid_l) {
		return find_m(k - 1);
	}
	else if (N > mid_r) {
		N = N - mid_r; // N 업데이트
		return find_m(k - 1);
	}
	else {
		// 가운데 부분
		if (N == mid_l) return 'm';
		else return 'o';
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	long long m_l = 3; // S(k)일 때 moo length
	s.push_back(m_l);

	while (N > m_l) {
		k++; // k 증가
		m_l = (m_l * 2 + k + 3);
		s.push_back(m_l);
	} // N을 포함하는 k 찾기

	cout << find_m(k);
}
