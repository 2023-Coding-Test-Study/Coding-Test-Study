#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;
    long long tot1=0, tot2=0;
    
    for(auto x: queue1){ // 큐1의 총합을 계산
        tot1 += x;
        q1.push(x);
    }
    
    for(auto x: queue2){ // 큐2의 총합을 계산
        tot2 += x;
        q2.push(x);
    }
    
    for(int i=0; i < queue1.size()*4; i++){
        if(tot1 == tot2) return i; // 같으면 출력
        
        if(tot1 > tot2){ // 앞에껄 빼서 더해줌~
            int x = q1.front();
            tot1 -= x;
            tot2 += x;
            q2.push(x);
            q1.pop();
        }
        else{
            int x = q2.front();
            tot2 -= x;
            tot1 += x;
            q1.push(x);
            q2.pop();
        }
    }
    return -1;
    
}
