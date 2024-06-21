#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<pair<int, int>> pq; // 이용중인 사용자의 종료, 사용한 자리 
priority_queue<int> seat; // 사용할 수 있는 자리 
int ans[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int k, l;
    for (int i = 0; i < N; i++) {
        cin >> k >> l; // 시작 끝
        v.push_back({ k, l });
    }

    sort(v.begin(), v.end()); // 시작 시간 빠른 순으로 정렬 
    int s = 0; // 사용하는 자리 개수 

    for (int i = 0; i < v.size(); i++) {

        while (!pq.empty()) {
            if (pq.top().first <= v[i].first) { // 이용중인 사람의 종료 시간이 현재 사람의 시작 시간보다 같거나 적으면
                seat.push(pq.top().second); // 사용할 수 있는 자리를 추가 
                pq.pop(); // 제거
            }
            else break;
        }

        if (seat.empty()) { // 사용할 수 있는 자리가 없으면 
            pq.push({ v[i].second, s });
            ans[s++]++; // 자리 추가 
        }  
        else { // 있으면 
            int tmp = seat.top();
            pq.push({ v[i].second, tmp });
            ans[tmp]++;
            seat.pop();
        }
    }

    cout << s << endl;
    for (int i = 0; i < s; i++)
        cout << ans[i] << " ";
}
