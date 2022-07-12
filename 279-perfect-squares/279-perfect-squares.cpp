class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,10001);
        dp[0] = 0;
        int t = (int)sqrt(n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=t; j++)
            {
                int x = j*j;
                if(i-x>=0)
                    dp[i] = min(dp[i], 1+dp[i-x]);
            }
        }
        return dp[n];
    }
};