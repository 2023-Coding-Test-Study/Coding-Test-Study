#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dun) {
    int ans = 0;
    sort(dun.begin(), dun.end()); // 오름차순 정렬 
    
    do{
        int curK = k;
        int cnt = 0; 
        
        for(int i = 0; i < dun.size(); i++){
            int required = dun[i][0];
            int consumed = dun[i][1];
            
            if(curK >= required){
                curK -= consumed;
                cnt++; 
            }
        }
        
        ans = max(ans, cnt);
    }while(next_permutation(dun.begin(), dun.end()));
    
    return ans; 
}