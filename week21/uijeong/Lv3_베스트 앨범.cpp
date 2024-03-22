#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp1(pair<string, int> &a, pair<string, int> &b){ // 장르별 정렬 
    return a.second >= b.second;
}


bool comp2(pair<int, int> &a, pair<int, int> &b){ // 각 장르의 노래별 정렬
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> album; // 장르별 노래, vlaue 값은 노래 횟수, 인덱스 번호
    map<string, int> play_time; // 총 노래 재생 횟수
    int song_size = genres.size(); // 총 노래 개수 
    
    for(int i=0; i < song_size; i++){
        int temp = 0;
        if(album.find(genres[i]) == album.end()){
            // 장르가 존재하지 않는 경우 
            vector<pair<int, int>> t = {{plays[i], i}};
            album.insert({genres[i], t}); // 재생 횟수, 고유번호
            play_time.insert({genres[i], plays[i]});
        }
        else{
            // 존재하는 경우 
            album[genres[i]].push_back({plays[i], i}); // 재생 횟수, 고유번호
            play_time[genres[i]] += plays[i]; // 총 노래 횟수 정하기 
        }
    } // 장르별 노래 분류 
    
    // 장르별 정렬 
    vector<pair<string, int>> s(play_time.begin(), play_time.end()); // map을 vector로 변환 
    sort(s.begin(), s.end(), comp1); // value 기준으로 정렬
    
    for(auto &a : album){ // 각 장르별 노래 횟수 정렬
        sort(a.second.begin(), a.second.end(), comp2); 
    }
    
    // 값 저장 
    for(int i=0; i < s.size(); i++){
        string g = s[i].first;
        if(album[g].size() == 1){
            answer.push_back(album[g][0].second);
        }
        else{
            answer.push_back(album[g][0].second);
            answer.push_back(album[g][1].second);
        }
    }
    
    return answer;
}
