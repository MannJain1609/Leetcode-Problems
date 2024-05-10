class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int Ti0_pre = 0, Ti0 = 0, Ti1 = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int Ti0_old = Ti0;
            Ti0 = max(Ti0, Ti1 + prices[i]);
            Ti1 = max(Ti1, Ti0_pre - prices[i]);
            Ti0_pre = Ti0_old;
        }
        return Ti0;
    }
};