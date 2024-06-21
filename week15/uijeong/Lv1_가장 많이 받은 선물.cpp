#include <bits/stdc++.h>

using namespace std;

int his[50][50];
int score[50]; // 선물 지수 

int solution(vector<string> friends, vector<string> gifts) {
    map<string, int> idx; // 이름과 원본 인덱스
    int answer = 0;

    for(int i=0; i < friends.size(); i++){
        idx.insert({friends[i], i});
    }

    for(int i = 0; i < gifts.size(); i++){
        string a = gifts[i].substr(0, gifts[i].find(" "));
        string b = gifts[i].substr(gifts[i].find(" ")+1);

        score[idx[a]]++; // 선물 지수 증가
        score[idx[b]]--; // 선물 지수 감소

        his[idx[a]][idx[b]]++; // 줬으니까 증가
				his[idx[b]][idx[a]]--; // 받았으니까 감소
    }

    for(int i=0; i < friends.size(); i++){
        int gift = 0;
		for(int j=0; j < friends.size(); j++){
            if(his[i][j] > 0){
                // 기록이 있는데 i가 j보다 더 많이 선물을 주었다! 
                gift++;
            }
            else if(his[i][j] == 0){
                // 선물 기록이 같다. 
                if(score[i] > score[j]){ // 선물 지수가 더 크면 
                    gift++; 
                }
            }
        }
        
        if(answer < gift){
            answer = gift;
        }
    }

    return answer;
}
