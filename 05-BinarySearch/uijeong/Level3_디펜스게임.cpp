#include <bits/stdc++.h>

using namespace std;

bool checkRound(int n, int k, vector<int> e){
    int sum = 0;
    sort(e.begin(), e.end(), greater<int>());
    
    for(int i = k; i < e.size(); i++){
        n -= e[i];
        if(n < 0){
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    int st = 0;
    int end = enemy.size()-1;
    
    while(st <= end){
        int mid = (st+end+1)/2;
        vector<int> temp;
        for(int i=0; i<= mid; i++){
            temp.push_back(enemy[i]);
        }
        
        if(checkRound(n,k,temp)){
            // true라면 
            answer = mid;
            st = mid+1; // mid까지 라운드 통과이므로 
        }
        else{
            // false라면
            end = mid-1;
        }
    }
    return answer+1;
}
