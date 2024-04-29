#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; 

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> arr(e + 1, 0); // 억억단에서의 등장 횟수 (약수의 개수) 
    vector<int> dp(e + 1, 0); // 가장 많이 등장한 숫자 
    
    int s = *min_element(starts.begin(), starts.end());
    
    // 억억단에서 특정 숫자의 등장 횟수 구하기 
    for(int i = 1; i <= e; i++){
        for(int j = 1; j <= e / i; j++){
            arr[i*j]++;
        }
    }
    
    dp[e] = e; // [e, e] 범위 중에서 가장 많이 등장한 숫자
    
    for(int i = e - 1; i >= s; i--){
        // 이제까지의 최대 등장 횟수보다 크거나 같으면, dp 테이블 갱신 
        // 같은 경우도 포함하는 이유는 가장 작은 숫자를 테이블에 저장하려고! 
        if(arr[i] >= arr[dp[i + 1]]) dp[i] = i; 
        // 그렇지 않으면, 이전 값 유지 
        else dp[i] = dp[i + 1];
    }
    
    // d[s] : [s, e] 범위에서 가장 많이 등장한 숫자 
    for(auto s: starts){
        answer.push_back(dp[s]);
    }
    
    return answer;
}