class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                    dp[i][j] = true;
                else if(j == i+1 && s[i]==s[j])
                    dp[i][j] = true;
                else if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(dp[i][j])
                    count++;
            }
        }
        return count;
    }
};