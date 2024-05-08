class Solution {
public:
    // bool isPalindrome(string s, int start, int end) {
    //     int n = (start+end)/2;
    //     int x = 0;
    //     for(int i=start; i<=n; i++)
    //     {
    //         if(s[i] != s[end-x])
    //             return false;
    //         x++;
    //     }
    //     return true;
    // }
    // int maxlen = 0;
    // string lonpal = "";
    // void helper(string s, int i, int j, vector<vector<bool>>& dp) {
    //     if(i == j) {
    //         if(maxlen < 1) {
    //             maxlen = 1;
    //             lonpal = s[i];
    //         }
    //         return;
    //     }
    //     if(dp[i][j])
    //         return;
    //     dp[i][j] = true;
    //     if(isPalindrome(s,i,j) && maxlen < j-i+1) {
    //         maxlen = j-i+1;
    //         lonpal = s.substr(i,maxlen);
    //         return true;
    //     }
    //     helper(s,i+1,j,dp);
    //     helper(s,i,j-1,dp);
    //     return;
        
    // }
    string longestPalindrome(string s) {
        // int size = s.size();
        // vector<vector<bool>>dp(size,vector<bool>(size,false));
        // helper(s,0,size-1,dp);
        // return lonpal;

        int size = s.size();
        vector<vector<bool>>dp(size,vector<bool>(size,false));
        int maxlen = 1;
        string ans;
        ans = s[0];
        for(int i=size-1; i>=0; i--)
        {
            dp[i][i] = true;

            for(int j=i+1; j<size; j++)
            {
                if(i+1 == j && s[i] == s[j]) {
                    dp[i][j] = true;
                }
                else if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1];
                }

                if(dp[i][j])
                {
                    if(maxlen < j-i+1)
                    {
                        maxlen = j-i+1;
                        ans = s.substr(i,maxlen);
                    }
                }
                 
            }
        }
        return ans;
    }
};