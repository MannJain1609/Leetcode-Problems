class Solution {
private:
    int helper(vector<int>& days, vector<int>& costs, int n, int ind,vector<int>& memo) {
        if(ind==n)
            return 0;
        if(memo[ind]!=-1)
            return memo[ind];
        int cost = INT_MAX;
        for(int i=0; i<3; i++) {
            int d;
            if(i==0)
            d = lower_bound(days.begin(),days.end(),days[ind]+1)-days.begin();
            if(i==1)
                d = lower_bound(days.begin(),days.end(),days[ind]+7)-days.begin();
            else if(i==2)
                d = lower_bound(days.begin(),days.end(),days[ind]+30)-days.begin();
            cost = min(cost, costs[i]+helper(days,costs,n,d,memo));
        }
        memo[ind] = cost;
        return cost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<unsigned int>dp(n+1,INT_MAX);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<3; j++)
            {
                int d;
                if(j==0)
                    d = lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
                else if(j==1)
                    d = lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
                else if(j==2)
                    d = lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
                dp[i] = min(dp[i],costs[j]+dp[d]);
            }
        }
        return dp[0];
        // vector<int>memo(n+1,-1);
        // return helper(days,costs,n,0,memo);
    }
};