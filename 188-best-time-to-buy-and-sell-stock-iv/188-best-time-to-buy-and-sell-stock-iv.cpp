class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if (days==0) 
            return 0;
        
        vector<vector<int>> dp(k+1,vector<int>(days,0));
        // Dp array with k+1 rows and days columns
        // dp[i][j] represents maximum profit of i transactions upto j days
        
        // dp[0][j] will be 0 as profit of 0 transactions is 0
        // dp[i][0] will be 0 as profit upto first day is 0
        
        for (int i=1;i<=k;i++) {
            int temp = -prices[0];
                
            for (int j=1;j<days;j++) {
                // dp[i][day] will be maximum of dp[i][day-1] and
                // dp[i-1][j]+new tx i.e max profit upto transaction i-1 and j<day
                
                int Max = dp[i][j-1];
                //bought on j-1th day and sold today
                temp = max(dp[i-1][j-1]-prices[j-1],temp);
                Max = max(Max,temp+prices[j]);
                
                dp[i][j] = Max;
            }
        }
        
        return dp[k][days-1];
    }
};