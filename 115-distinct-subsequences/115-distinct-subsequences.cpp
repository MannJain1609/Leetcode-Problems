class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<unsigned long long>>dp(m+1,vector<unsigned long long>(n+1,0));
        for(int i=0; i<=m; i++)
            dp[i][0] = 1;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j>i)
                    dp[i][j] = 0;
                else if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
}; 