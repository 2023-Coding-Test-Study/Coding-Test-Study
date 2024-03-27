#include <iostream> 
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm> 
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii; 

// 장르별 총 재생 횟수 계산 (중복 없음)
// -> 장르 순서 배치
// 장르 내에서 노래별 재생 횟수 (top 2개만 베스트 앨범에 수록 -> 1개인 경우 1개만)
// -> 노래 순서 배치 (만약 재생 횟수가 같으면 고유번호 순으로)
bool compare(pii a, pii b){
    if(a.first == b.first){
        // 고유 번호 오름차순 
        return a.second < b.second; 
    }
    
    return a.first > b.first; // 재생 횟수 내림차순 
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    set<string> s;
    for(auto g: genres){
        s.insert(g);
    }
    
    // 장르별 총 재생 횟수
    map<string, int> m;
    for(auto name: s){
        int sum = 0;
        for(int i = 0; i < genres.size(); i++){
            if(name == genres[i]){
                sum += plays[i];
            }
        }
        m[name] = sum; 
    }
    
    // 재생 횟수 높은 순으로 장르 순서 정렬
    vector<pair<int, string>> v; // {재생 횟수, 장르 이름}
    for(auto e: m){
        v.push_back({e.second, e.first});
    }
    sort(v.begin(), v.end(), greater<pair<int, string>>());
    
    // 장르 내에서 노래별 -> {재생 횟수, 고유 번호}
    // 3100 P -> {2500, 4} {600, 1}
    // 1950 X -> {800, 3} {500, 0} {500, 5} {150, 2}
    // 500  Z -> {500, 6}
    // ans : 4 1 3 0 6 
    vector<vector<pii>> nums(v.size());
    
    for(int i = 0; i < v.size(); i++){
        string g = v[i].second;
        for(int j = 0; j < genres.size(); j++){
            if(g == genres[j]) {
                nums[i].push_back({plays[j], j});
            }
        }
    }
    
    for(int i = 0; i < nums.size(); i++){
    	// 각 장르 내에서 재생 횟수는 내림차순, 고유 번호는 오름차순으로 정렬 
        sort(nums[i].begin(), nums[i].end(), compare);
        
        // 가장 재생 횟수가 높은 2개만 정답으로 저장 
        int a = nums[i][0].second;
        answer.push_back(a);
        
        if (nums[i].size() == 1) continue;
        else {
            int b = nums[i][1].second;
            answer.push_back(b);
        }
    }
    
    return answer;
}