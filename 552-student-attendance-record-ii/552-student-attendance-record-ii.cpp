//#define MOD 1000000007
class Solution {
private:
    // int count = 0;
    // bool isValid(string s, int n)
    // {
    //     int c = 0;
    //     for(int i=0; i<n; i++)
    //     {
    //         if(s[i] == 'A')
    //             c++;
    //         if(c>1)
    //             return false;
    //         if(s[i] == 'L') {
    //             if(i>0 && i<n-1 && s[i-1] == s[i+1] && s[i+1] == 'L')
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
    // void helper(int n, string st)
    // {
    //     if(st.size() == n) {
    //         if(isValid(st,n))
    //             count = (count+1)%MOD;
    //         return;
    //     }
    //     string s = "PAL";
    //     for(int i=0; i<3; i++)
    //     {
    //         helper(n,st+s[i]);
    //     }
    // }
    int solve(int n, int absent, int late, int dp[][2][3])
    {
        int MOD = 1000000007;
        if(absent>=2 || late>=3)
            return 0;
        if(dp[n][absent][late]!=-1)
            return dp[n][absent][late];
        if(n==0)
            return 1;
        ///present
        int p =solve(n-1,absent,0,dp);
        //absent
        int a = solve(n-1,absent+1,0,dp);
        //late
        int l = solve(n-1,absent,late+1,dp);
        
        return dp[n][absent][late] = ((p+a)%MOD+l)%MOD;
    }
public:
    int checkRecord(int n) {
        int dp[n+1][2][3];
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,dp);
    }
};