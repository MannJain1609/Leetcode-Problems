class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min = prices[0];
        int maxProfit = 0;
        int size = prices.size();
        for (int i=0;i<size;i++) {
            Min = min(Min,prices[i]);
            maxProfit = max(maxProfit,prices[i]-Min);
        }
        
        return maxProfit;
    }
};