class Solution {
public:
    //int ans = INT_MAX;
    bool isValid(string st)
    {
        int freq[26] = {0};
        for(char c: st)
            freq[c-'a']++;
        int count = freq[st[0]-'a'];
        for(int i=0; i<26; i++)
        {
            if(freq[i]>0 && freq[i] != count)
                return false;
        }
        return true;
        
    }
    int helper2(string& s, int n, int i, vector<int>& dp)
    {
        if(i == n)
            return 0;
        if(i == n-1)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        int ways = INT_MAX;
        int freq[26] = {0};
        for(int j=i; j<n; j++)
        {
            freq[s[j]-'a']++;
            int min_freq = 1001, max_freq = 0;
            for(int i=0; i<26; i++)
            {
                if(freq[i] > 0)
                {
                    min_freq = min(min_freq,freq[i]);
                    max_freq = max(max_freq, freq[i]);
                }
            }
            if(min_freq == max_freq)
                ways = min(ways, 1 + helper2(s,n,j+1,dp));
        }
        return dp[i] = ways;
    }

    int helper(string& s, int n, int i, int j, vector<vector<int>>& dp)
    {
        if(i==n && i == j)
            return 0;
        if(i == n || j == n)
            return 1001;
        if(dp[i][j] != -1)
            return dp[i][j];
        int take = INT_MAX;
        if(isValid(s.substr(i,j-i+1)))
        {
            take = 1+helper(s,n,j+1,j+1,dp);
        }
        int not_take = helper(s,n,i,j+1,dp);
        return dp[i][j] = min(take,not_take);
    }

//     void helper(string& s, int n, int i, int subs)
//     {
//         if(i == n) {
//             ans = min(ans,subs);
//             return;
//         }
        
//         for(int j=i; j<n; j++)
//         {
//             string st = s.substr(i,j-i+1);
//             if(isValid(st))
//             {
//                 helper(s,n,j+1,subs+1);
//             }
//         }
//     }
    int minimumSubstringsInPartition(string s) {
        int  n = s.size();
        if(isValid(s))
            return 1;
        vector<int>dp(n,-1);
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        //return helper(s,n,0,0,dp);
        return helper2(s,n,0,dp);
        //return ans;
    }
};