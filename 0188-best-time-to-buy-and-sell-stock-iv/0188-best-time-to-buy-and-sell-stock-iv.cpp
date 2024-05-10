class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= (n>>1))
        {
            //similar to infinite transactions
            int Ti0 = 0, Ti1 = INT_MIN;
            for(int i=0; i<n; i++)
            {
                int Ti0_old = Ti0;
                Ti0 = max(Ti0, Ti1 + prices[i]);
                Ti1 = max(Ti1, Ti0_old - prices[i]);
            }
            return Ti0;
        }
        else 
        {
            vector<int>Ti0(k+1,0);
            vector<int>Ti1(k+1,INT_MIN);
            for(int i=0; i<n; i++)
            {
                for(int j=1; j<=k; j++)
                {
                    Ti0[j] = max(Ti0[j], Ti1[j] + prices[i]);
                    Ti1[j] = max(Ti1[j], Ti0[j-1] - prices[i]);
                }
            }
            return Ti0[k];
        }
        return 0;
    }
};