class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int size = s3.size();
        if(size!=m+n)
            return false;
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = s3.substr(0,j) == s2.substr(0,j);
                else if(j == 0)
                    dp[i][j] = s3.substr(0,i) == s1.substr(0,i);
                else
                    dp[i][j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1]) ||
                                (dp[i][j-1] && s3[i+j-1] == s2[j-1]);
            }
        }
        return dp[n][m] == 1;
    }
};