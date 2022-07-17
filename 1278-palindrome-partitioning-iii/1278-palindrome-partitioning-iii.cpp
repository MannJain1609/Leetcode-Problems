class Solution {
private:
    int minCharChange(string& s, int i, int j)
    {
        int change = 0;
        while (i<j) {
            if (s[i]!=s[j])
                change++;
            i++;
            j--;
        }
        return change;
    }
    int solve(string& s, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if(i>j)
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(k==1)
            return dp[i][j][k] = minCharChange(s,i,j);
        int min_change = INT_MAX;
        for(int x = i; x<j; x++)
        {
            int a = solve(s,i,x,1,dp);
            int b = solve(s,x+1,j,k-1,dp);
            if(a==INT_MAX || b == INT_MAX)
                continue;
            int change = a+b;
            min_change = min(min_change,change);
        }
        return dp[i][j][k]=min_change;
    }
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(s,0,n-1,k,dp);
    }
};