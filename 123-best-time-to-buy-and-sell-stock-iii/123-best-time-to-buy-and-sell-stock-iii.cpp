class Solution {
private:
    int helper(vector<int>& prices, vector<vector<vector<int>>>& dp, int size,
              int buy, int pos, int k) {
        if(pos>=size || k==2)
            return 0;
        if(dp[pos][buy][k]!=-1)
            return dp[pos][buy][k];
        int ans = 0;
        if(buy)
        {
            ans = max(-prices[pos]+helper(prices,dp,size,0,pos+1,k),
                               helper(prices,dp,size,1,pos+1,k));
        }
        else
        {
            ans = max(prices[pos]+helper(prices,dp,size,1,pos+1,k+1),
                               helper(prices,dp,size,0,pos+1,k));
        }
        dp[pos][buy][k] = ans;
        return ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,dp,size,1,0,0);
    }
};