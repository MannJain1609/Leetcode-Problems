const int MOD = 1e9 + 7;
class Solution {
public:
    int ways = 0;
    int helper2(vector<vector<int>>& freq, string& target, int size, int wordLen, int i, int j, vector<vector<int>>& dp) {
        //cout<<i<<" "<<j<<endl;
        if(i == size) {
            return 1;
        }
        if(j >= wordLen || (size-i) > (wordLen-j))
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int take = 0;
        int not_take = 0;
        if(freq[target[i] - 'a'][j] > 0) {
            long long temp = (freq[target[i]-'a'][j] * (long long)helper2(freq,target,size,wordLen,i+1,j+1,dp)%MOD)%MOD;
            take = temp%MOD;
        }
        not_take = helper2(freq,target,size,wordLen,i, j+1,dp)%MOD;
        //cout<<freq[target[i]-'a'][i]<<endl;
        //cout<<i<<" "<<j<<" "<<take<<" "<<not_take<<" "<<endl;
        long long r = (take + not_take)%MOD;
        return dp[i][j] = r%MOD;
    }
    void helper(vector<vector<int>>& freq, string& target, int size,int wordLen, int i, int j, int ans) {
        if(i >= size) {
            //cout<<ans<<endl;
            ways = (ways+ans)%MOD;
            ans = 1;
            return ;
        }
        if(j >= wordLen || (size-i) > (wordLen-j))
            return;
        //cout<<i<<" "<<j<<" "<<ans<<endl;
        for(int ind = j; ind< wordLen; ind++)
        {
            //cout<<"ind: "<<ind<<" "<<i<<" "<<j<<" "<<endl;
            if(freq[target[i]-'a'][ind] == 0)
                continue;
            int prev = ans;
            long long temp = (((long long)ans%MOD) * freq[target[i]-'a'][ind])%MOD;
            ans = temp%MOD;
            helper(freq,target,size, wordLen,i+1,ind+1,ans);
            ans = prev;
            //cout<<i<<" "<<j<<" "<<ind<<" "<<ans<<endl;
        }
    }
    int numWays(vector<string>& words, string target) {
        int wordLen = words[0].size();
        int size = target.size();
        vector<vector<int>>freq(26, vector<int>(wordLen,0));
        for(string& s : words) {
            for(int i=0; i<wordLen; i++)
            {
                freq[s[i]-'a'][i] ++;
            }
        }
        vector<vector<int>>dp(size, vector<int>(wordLen,-1));

        return helper2(freq,target,size,wordLen,0,0,dp);
        // helper(freq,target,size,wordLen ,0,0,1);
        // return ways;
    }
};