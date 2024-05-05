class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>>dp(size1 +1 , vector<int>(size2+1, 0));
        for(int i=0; i<=size2; i++) {
            dp[0][i] = i;
        }
        for(int i=0; i<=size1; i++) {
            dp[i][0] = i;
        }
        for(int i=1; i<=size1; i++)
        {
            for(int j=1; j<=size2; j++)
            {
                dp[i][j] = min(1 + dp[i][j-1], min(1 + dp[i-1][j],1 + dp[i-1][j-1]));
                if(word2[j-1] == word1[i-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[size1][size2];
    }
};