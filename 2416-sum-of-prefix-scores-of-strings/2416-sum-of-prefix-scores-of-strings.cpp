class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& s) {
        unordered_map<long long,int>mp;
        long long base = 31,mod = 1111111111111111;
        int size = s.size();
        for(int i=0; i<size; i++)
        {
            long long hash = 0,pw = 1;
            int len = s[i].size();
            for(int j=0; j<len; j++)
            {
                int x = s[i][j] - 'a' + 1;
                mp[hash = (hash + (pw * x) % mod)%mod]++;
                pw = (pw*base) % mod;
            }
        }
        vector<int>ans(size,0);
        for(int i=0; i<size; i++)
        {
            int len = s[i].size();
            long long hash = 0,pw=1;
            for(int j=0; j<len; j++)
            {
                ans[i]+=mp[hash = (hash + (pw * (s[i][j]-'a'+1))%mod)%mod];
                pw = (pw*base) % mod;
            }
        }
        return ans;
    }
};