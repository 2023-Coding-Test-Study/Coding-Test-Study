#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int s = triangle.size(); // 삼각형의 높이 
    vector<vector<int>> d(s, vector<int>(s, 0));  
    
    d[0][0] = triangle[0][0]; // 초기화 
    for(int i= 1; i < s; i++){
        for(int j= 0; j < triangle[i].size(); j++){
            if(j == 0){ // 맨 왼쪽의 경로가 마지막 도착지라면
                d[i][j] = d[i-1][j] + triangle[i][j];
            }
            else if(j == triangle[i].size()-1){
                d[i][j] = d[i-1][j] + triangle[i][j];
            }
            else{
                d[i][j] = triangle[i][j] + max(d[i-1][j-1], d[i-1][j+1]);
            }
        }
    }

    for(int i = 0; i < s; i++){
        answer = max(d[s-1][i], answer);
    }
    return answer;
}
