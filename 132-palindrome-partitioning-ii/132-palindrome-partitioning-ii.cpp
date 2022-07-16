class Solution {
private:
    int solve(string& s, int i, int j, vector<vector<int>>& dp,vector<vector<bool>>& p)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(p[i][j])
            return 0;
        int min_cuts = INT_MAX;
        for(int k = i; k<j; k++)
        {
            if (!p[i][k])
                continue;
            int a = solve(s,i,k,dp,p);
            int b = solve(s,k+1,j,dp,p);
            
            int cuts = 1 + a+b;
            min_cuts = min(min_cuts,cuts);
        }
        return dp[i][j] = min_cuts;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        vector<vector<bool>>p(n,vector<bool>(n,false));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                    p[i][j] = true;
                else if(j == i+1 && s[i]==s[j])
                    p[i][j] = true;
                else if(s[i] == s[j])
                    p[i][j] = p[i+1][j-1];
            }
        }
        
        return solve(s,0,n-1,dp,p);
    }
};