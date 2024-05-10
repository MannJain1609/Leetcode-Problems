class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int Ti0 = 0, Ti1 = INT_MIN;
        int n = prices.size();
        for(int i=0; i<n; i++)
        {
            int T_i0_old = Ti0;
            Ti0 = max(Ti0,Ti1 + prices[i]);
            Ti1 = max(Ti1,T_i0_old-prices[i]-fee);
        }
        return Ti0;
    }
};