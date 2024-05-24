class Solution {
public:
    
    int helper(int n, vector<int>& cuts, int left, int right, vector<vector<int>>& dp)
    {
        if(right - left <= 1) //no cuts between them
            return  0;
        if(dp[left][right] != -1)
            return dp[left][right];
        
        int ans = INT_MAX;
        for(int mid = left+1; mid < right; mid++)
        {
            int cost =  helper(n,cuts,left,mid,dp) + helper(n,cuts,mid,right,dp) + cuts[right] - cuts[left];
            ans = min(ans,cost);

        }
        return dp[left][right] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return helper(n,cuts,0,m-1,dp);
    }
};