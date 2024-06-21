#include <bits/stdc++.h>
using namespace std;

int N, M;
pair<long long, long long> meat[1000001];

bool comp(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == b.first) return a.second > b.second; // 더 무거운거 
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> meat[i].second >> meat[i].first;
    }

    sort(meat, meat+N, comp); // first(가격)를 기준으로 오름차순 

    long long sum_w = 0; // 무게
    long long sum_p = 0; // 가격
    int price = -1;
    for (int i = 0; i < N; i++) {
        if (sum_w >=  M) {
            break;
        }

        // 무게가 적다면 
        if (price == meat[i].first) {
            // 이전 가격과 같다면 
            sum_p += meat[i].first; // 추가 구매
        }
        else { // 가격이 더 비싼 경우
            sum_p = meat[i].first; // 이거 하나만 사도 되니까 sum_p 업데이트 
            price = meat[i].first; // 이전 가격 업데이트
        }

        sum_w += meat[i].second; // 고기 무게 더해주기
    
    }

    if (sum_w < M) cout << -1;
    else cout << sum_p;
}
