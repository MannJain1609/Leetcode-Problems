class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int days = prices.size();
        //profit til; date having one share in hand
        int buy = -1*prices[0];
        //profit till date having no share in hand
        int sell = 0;
        for(int day=1; day<days; day++)
        {
            int new_buy = sell - prices[day];
            int new_sell = buy + prices[day] - fee;
            sell = max(sell,new_sell);
            buy =  max(buy,new_buy);
        }
        return sell;
    }
};