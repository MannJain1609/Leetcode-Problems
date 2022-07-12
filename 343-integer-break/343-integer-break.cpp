class Solution {
public:
    int integerBreak(int n) {
        //every number can be break into sum of some ones
        vector<int>dp(n+1,1);
        //Anything multiply by zero is zero
        dp[0] = 0;
        for(int i =2; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                //Minimum two numbers required
                if(i-j>0) {
                    dp[i] = max(dp[i], max(j*dp[i-j],j*(i-j)));
                }
            }
        }
        return dp[n];
    }
};