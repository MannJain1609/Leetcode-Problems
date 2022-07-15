class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int size = s.size();
        unordered_map<char,int>mp;
        int prev[size];
        int next[size];
        for(int i=0; i<size; i++)
        {
            if(mp.find(s[i])==mp.end())
                prev[i] = -1;
            else
                prev[i] = mp[s[i]];
            mp[s[i]] = i;
        }
        mp.clear();
        for(int i=size-1; i>=0; i--)
        {
            if(mp.find(s[i])==mp.end())
                next[i] = -1;
            else
                next[i] = mp[s[i]];
            mp[s[i]] = i;
        }
        int MOD = 1e9 + 7;
        vector<vector<int>>dp(size,vector<int>(size,0));
        //dp[i][j] -> num of distinct palindromic subsequences from index i to j inclusive
        
        for(int i=size-1; i>=0; i--)
        {
            for(int j=i; j<size; j++)
            {
                //The char itself of one len is a palindrome
                if(i==j)
                    dp[i][j] = 1;
                
                //any string of len 2 has palindromic subsequences 2
                //if string has diff characters as ab then two seq-> a, b
                //if string has same characters as aa then two seq-> a, aa
                else if(j == i+1)
                    dp[i][j] = 2;
                
                else if(s[i] == s[j]) 
                {
                    int nxt = next[i];
                    int prv = prev[j];
                    
                    if(nxt>prv)
                    {
                        //There is no character equal to s[i] between i and j
                        //There are two subsequences that can be formed from i & j,
                        //taking the char once and twice, and these are not counted yet.
                        //one seq will be from i+1 to j-1
                        //one seq will be from i+1 to j-1 including the i and j
                        //ex abca = dp[bc]+dp[bc]+a+aa 
                        //first dp[bc] = b,c
                        //second dp[bc] = aba,aca
                        dp[i][j] = 2*dp[i+1][j-1] + 2;
                    }
                    else if(nxt == prv)
                    {
                        //There is exactly one character equal to s[i] between i and j
                        //Now, there is exactly one unique seq that can be formed from i and j,
                        //taking both i and j characters as single i character is already counted
                        //Rest there will be 2*dp[i+1][j-1], same as prev
                        //ex abaca = 2*dp[bac] + aa
                        //first dp[bac] = b,a,c
                        //second dp[bac] = aba,aaa,aca
                        dp[i][j] = 2*dp[i+1][j-1] + 1;
                    }
                    //nxt<prv
                    else
                    {
                        //There are more than one characters equal to s[i] in between i and j
                        //No unique seq can be generated from i and j as both are already counted
                        //The seq between nxt and prev will be counted twice, so we subtract it
                        //ex abacada = 2*dp[bacad] - dp[c]
                        //first dp[bacad] = b,a,c,d,aca
                        //second dp[bacad] = aba,aaa,aca,ada,aacaa
                        //aca is counted twice, so we subtract it
                        dp[i][j] = 2*dp[i+1][j-1] - dp[nxt+1][prv-1];
                    }
                }
                
                //s[i]!=s[j]
                else
                {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
                //To handle mod
                if(dp[i][j]<0)
                    dp[i][j] = dp[i][j]+MOD;
                else
                    dp[i][j] = dp[i][j]%MOD;
            }
        }
        return dp[0][size-1];
    }
};