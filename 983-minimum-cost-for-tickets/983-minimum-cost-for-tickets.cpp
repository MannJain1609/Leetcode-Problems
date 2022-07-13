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
        vector<int>memo(n+1,-1);
        return helper(days,costs,n,0,memo);
    }
};