class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Ti20 = 0, Ti21 = INT_MIN;
        int Ti10 = 0, Ti11 = INT_MIN;
        for(int price : prices)
        {
           Ti20 = max(Ti20, Ti21 + price);
           Ti21 = max(Ti21, Ti10 - price);
           Ti10 = max(Ti10, Ti11 + price);
           Ti11 = max(Ti11, -price);
        }
        return Ti20;
    }
};