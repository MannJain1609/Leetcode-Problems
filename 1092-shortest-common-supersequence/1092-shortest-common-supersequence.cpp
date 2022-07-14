class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m = X.size();
        int n = Y.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i == 0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else {
                    if(X[i-1] == Y[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //Print
        string ss = "";
        int i=m-1,j=n-1;
        while(i>=0 && j>=0) {
            if(X[i] == Y[j]) {
                ss = X[i]+ss;
                i--;
                j--;
            }
            else if(dp[i][j+1]>dp[i+1][j]) {
                ss = Y[j] + ss;
                j--;
            }
            else {
                ss = X[i] + ss;
                i--;
            }
        }
        while(i>=0) {
            ss = X[i]+ss;
            i--;
        }
        while(j>=0) {
            ss = Y[j]+ss;
            j--;
        }
        return ss;
    }
};