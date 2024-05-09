class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int maxSoFar = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(maxSoFar < prices[i])
                maxSoFar = prices[i];
            maxProfit = max(maxProfit, maxSoFar - prices[i]);
        }
        return maxProfit;
    }
};