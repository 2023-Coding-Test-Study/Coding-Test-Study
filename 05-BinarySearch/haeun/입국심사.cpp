#include <string>
#include <vector>
#include <algorithm>
typedef long long ll; 
using namespace std;

bool decision(vector<int> times, int n, ll mid){
    ll sum = 0;
    for(int i = 0; i < times.size(); i++){
        sum += mid / times[i];
    }
    return sum >= n;
}

ll solution(int n, vector<int> times) {
    ll left = 1;
    int maxTime = *max_element(times.begin(), times.end()); 

    // long long형으로 명시적 캐스팅 필수!!!
    ll right = 1LL * maxTime * n;  
    ll ans = right; 
    
    while(left <= right){
        ll mid = (left + right) / 2;
        
        if(decision(times, n, mid)) {
        	ans = min(ans, mid); 
        	right = mid - 1; 
		}
        else left = mid + 1; 
    }
    
    return ans;
}