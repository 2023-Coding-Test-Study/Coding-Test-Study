#include <bits/stdc++.h>

using namespace std;

int stick = 0, eight = 0;
vector<int> in(1000001);
vector<int> out(1000001);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int last = 0;
    for(auto x: edges){
        out[x[0]]++; // 나가는 간선
        in[x[1]]++; // 들어오는 간선
        last = max(last, max(x[0], x[1])); // 노드의 개수 
    }

    // 그래프 및 노드 찾기 
    int n = 0;
    for(int i=1; i <= last; i++){
        if(out[i] >= 2 && in[i] == 0) n = i; // 정점 - 나가는게 2개 이상 들어오는게 없음
        else if(out[i] >= 2 && in[i] >= 2) eight++; // 8자 - 특정노드가 나가는게 2개 들어오는게 2개 
        else if(out[i] == 0) stick++; // 막대 - 특정 노드가 나가는게 0개
        else continue;
    }
    
    answer.push_back(n);
    answer.push_back(out[n] - stick - eight);
    answer.push_back(stick);
    answer.push_back(eight);
    return answer;
}
