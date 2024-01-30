#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int N = people.size();

    sort(people.begin(), people.end());
    int idx = 0;
    while (idx < people.size()) { // 모든 인원이 보트에 탔음! 
        int back = people.back();
        people.pop_back();
        if (people[idx] + back <= limit) { answer++; idx++; } // 같이 탐! 
        else answer; // 혼자 탐! 
    }
    return answer++;
};
