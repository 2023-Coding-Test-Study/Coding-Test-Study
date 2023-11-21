#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp1, temp2;

        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1, temp2));
    }

    sort(v.begin(), v.end(), comp); // 문제 분석에 의한 정렬

    int end = v[0].second;
    int count = 1;
    for (int i = 1; i < v.size(); i++) {
        if (end <= v[i].first) { // 그 다음 회의인 경
            count++;
            end = v[i].second;
        }
    }

    cout << count;
}
