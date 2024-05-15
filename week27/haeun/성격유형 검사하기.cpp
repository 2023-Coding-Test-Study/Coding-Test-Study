#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// 1/4 -> 0 
// 2/4 -> 0 
// 3/4 -> 0 
// 4/4 -> - 
// 5/4 -> 1
// 6/4 -> 1 
// 7/4 -> 1 

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> m; 
    for(int i = 0; i < survey.size(); i++){
        if(choices[i] != 4){
            char type = survey[i][choices[i]/4];
            int score = abs(choices[i] - 4);
            m[type] += score;
        }
    }
    
    answer += m['R'] >= m['T'] ? 'R' : 'T';
    answer += m['C'] >= m['F'] ? 'C' : 'F';
    answer += m['J'] >= m['M'] ? 'J' : 'M';
    answer += m['A'] >= m['N'] ? 'A' : 'N';
    
    return answer;
}