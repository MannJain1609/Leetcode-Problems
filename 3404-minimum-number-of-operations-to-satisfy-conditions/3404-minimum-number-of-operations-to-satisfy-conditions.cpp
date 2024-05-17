class Solution {
public:

    int dfs(int i, int prev, int n, vector<vector<int>>& cnt, vector<vector<int>>& dp)
    {
        if(i == n)
            return 0;
        
        if(dp[i][prev] == 0)
        {
            for(int v = 0; v<10; v++)
            {
                if(i == 0 || prev != v)
                    dp[i][prev] = max(dp[i][prev], cnt[i][v] + dfs(i+1,v,n,cnt,dp)); 
            }
        }
        return dp[i][prev];
    }

    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(10,0));
        vector<vector<int>>cnt(n,vector<int>(10,0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cnt[i][grid[j][i]]++;
            }
        }
        
        return m * n - dfs(0,0,n,cnt,dp);
    }  
};