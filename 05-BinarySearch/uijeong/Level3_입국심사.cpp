#include <bits/stdc++.h>

using namespace std;

bool checkT(int mid, int n, vector<int> times){
    iong long count = 0;
    for(int i = 0; i < times.size(); i++){
        count += mid / times[i]; 
    }
    
    return count >= n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end()); // 오름차순 
    
    long long st = 1;
    long long end = times[times.size()-1] * n; // 최대 시간 
    
    while(st <= end){
        long long mid = (st+end)/2;
        
        if(checkT(mid, n, times)){
            // 사람 명수가 더 많으면 
            answer = mid;
            end = mid-1; // mid를 줄여봐야 
        }
        else{
            // 적으면
            st = mid+1; // mid를 더 늘려야..
        }
    }
    
    return answer;
}
