class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        
        unordered_map<char,int>mp;
        int prev[n];
        int next[n];
        for(int i=0; i<n; i++)
        {
            if(mp.find(s[i])==mp.end())
                prev[i] = -1;
            else
                prev[i] = mp[s[i]];
            mp[s[i]] = i;
        }
    
        int MOD = 1e9 + 7;
        unordered_set<char>t;
        vector<unsigned long long>dp(n+1,0);
        for(int j=1; j<=n; j++)
        {
            if(j==1)
                dp[j] = 1;
            else if(t.count(s[j-1])==0)
                dp[j] = (1 + 2*dp[j-1])%MOD;
            //s[j] is present
            else {
                int prv = prev[j-1];
                if(prv ==0)
                    dp[j] = 2*dp[j-1]%MOD;
                else
                    dp[j] = (2*dp[j-1]-dp[prv]+MOD)%MOD;
            }
            t.insert(s[j-1]);
            if(dp[j]<0)
                dp[j]+=MOD;
        }
        return (int)dp[n];
    }
};