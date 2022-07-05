class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int buyStateProfit = -1*prices[0],sellStateProfit = 0, coolDownState = 0;
        for(int i=1; i<size; i++)
        {
            int new_buy = coolDownState - prices[i];
            int new_sell = buyStateProfit + prices[i];
            int new_cool = sellStateProfit;
            buyStateProfit = max(buyStateProfit,new_buy);
            coolDownState = max(coolDownState, new_cool);
            sellStateProfit = max(sellStateProfit,new_sell);
        }
        return sellStateProfit;
    }
};