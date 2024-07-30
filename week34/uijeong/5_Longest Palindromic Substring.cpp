class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        string d[1001][1001];
        int len = s.size();

        for(int i=0; i < len; i++){
            d[i][i] = s[i]; // 초기값, 자기자신은 같음 
        }

        for(int k=1; k < len; k++){ // 길이 변수 
            for(int st=0; st < len; i++){
                if(s[i] == s[end]){
                    // 양 끝값이 같다면? 
                    d[i][i+j] = d[i][end-1] + s[end]; // 양쪽 끝 이어붙이기
                }
                else{ // 같지 않은 경우
                    d[st][end] = d[st][end-1]; // 기존에 있던거
                }
            }

        }
        return d[0][len-1];
    }
};
