class Solution {
// private:
//     int helper(vector<int>& prices, vector<vector<vector<int>>>& dp, int size,
//               int buy, int pos, int k) {
//         if(pos>=size || k==2)
//             return 0;
//         if(dp[pos][buy][k]!=-1)
//             return dp[pos][buy][k];
//         int ans = 0;
//         if(buy)
//         {
//             ans = max(-prices[pos]+helper(prices,dp,size,0,pos+1,k),
//                                helper(prices,dp,size,1,pos+1,k));
//         }
//         else
//         {
//             ans = max(prices[pos]+helper(prices,dp,size,1,pos+1,k+1),
//                                helper(prices,dp,size,0,pos+1,k));
//         }
//         dp[pos][buy][k] = ans;
//         return ans;
//     }
public:
    int maxProfit(vector<int>& prices) {
        // int size = prices.size();
        // vector<vector<vector<int>>> dp(size,vector<vector<int>>(2,vector<int>(3,-1)));
        // return helper(prices,dp,size,1,0,0);
        
        
        int n = prices.size();
        
        // Iterating from left to right
        // Creating a dp of array represnting maximum profit if sold till today
        
        int minSoFar = prices[0]; // Represents buy
        int profitIfSoldToday = 0;
        vector<int> dpleft(n);
        
        for (int i=1;i<n;i++) {
            if (prices[i]<minSoFar) {
                minSoFar = prices[i];
            }
            
            profitIfSoldToday = prices[i]-minSoFar;
            
            if (profitIfSoldToday > dpleft[i-1]) {
                dpleft[i] = profitIfSoldToday;
            }
            else {
                dpleft[i] = dpleft[i-1];
            }
        }
        
        // Iterating from right to left
        // Creating a dp of array representing maximum profit 
        // if bought today or after today
        
        int maxAfterToday = prices[n-1]; // Represents sell
        int profitIfBoughtToday = 0;
        vector<int> dpright(n);
        
        for (int i=n-2;i>=0;i--) {
            if (prices[i]>maxAfterToday) {
                maxAfterToday = prices[i];
            }
            
            profitIfBoughtToday = maxAfterToday-prices[i];
            
            dpright[i] = max(dpright[i+1],profitIfBoughtToday);
        }
        
        // Now at a particular day i
        // dpleft[i] represents maximum profit if sold till today - Tx1
        // dpright[i] represents maximum profit if bought today or after today - Tx2
        // Maximum sum of the two is the maximum profit answer
        
        int maxProfit = dpleft[0]+dpright[0];
        for (int i=1;i<n;i++) {
            int temp = dpleft[i]+dpright[i];
            maxProfit = max(maxProfit,temp);
        }
        return maxProfit;
    }
};