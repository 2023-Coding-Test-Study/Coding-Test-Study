class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[501][501];
        int m = word1.size();
        int n = word2.size();

        // 1. Initalize
        for(int i=0; i <= m; i++){
            dp[i][0] = i; // delete
        }

        for(int i=0; i <= n; i++){
            dp[0][i] = i; // insert
        } 

        // 2. dynamic programming
        for(int i=1; i <= m; i++){
            for(int j=1; j<= n; j++){
                if(word1[i-1] == word2[j-1]){ // same
                    dp[i][j] = dp[i-1][j-1]; 
                }
                else{ // different 
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) +1; // replace, delete, insert
                }
            }
        }

        return dp[m][n];
    }
};
