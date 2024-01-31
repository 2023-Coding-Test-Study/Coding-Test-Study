#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int boatNum = 0;
    
    sort(people.begin(), people.end());
    
    int idx = 0;
    while(idx < people.size()){
        int sum = people[idx] + people.back(); 
        if(sum <= limit){
            idx++;
        }
        people.pop_back();
        boatNum++;
    }
    
    return boatNum;
}