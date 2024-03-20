#include <bits/stdc++.h>

using namespace std;

bool check(int mid, int k, vector<int> s){
    int cnt = 0; // 연속의 돌 개수 
    for(int i=0; i < s.size(); i++){
        if(s[i] <= mid) cnt++;
        else cnt = 0; // 초기화 
        
        if(cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int st = 1; // 돌 무게는 1부터 
    int ed = *max_element(stones.begin(), stones.end()); // 최대 무게 
    
    while(st <= ed){
        int mid = (st+ed) / 2;
        
        if(check(mid, k, stones)){
            // true인 경우
            st = mid + 1;
        }
        else ed = mid-1;
    }
    
    return st;
}
