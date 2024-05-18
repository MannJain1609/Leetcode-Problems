class Solution {
public:
    const int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_set<int>s;
        for(int a: arr)
        {
            s.insert(a);
        }
        int n = arr.size();
        vector<long long>dp(n,0);
        sort(arr.begin(), arr.end());
        dp[0] = 1;
        long long ans =0;
        ans += dp[0];
        for(int i=1; i<n; i++)
        {
            dp[i] = 1;
            for(int j=0; j<i; j++)
            {
                if(arr[i]%arr[j] != 0)
                    continue;
                int x = arr[i]/arr[j];
                if(s.find(x) != s.end()) {
                    int ind = lower_bound(arr.begin(), arr.end(),x) - arr.begin();
                    dp[i] += ((long long)dp[ind] * dp[j]);
                }
            }
            ans += dp[i];
        }
        return ans%MOD;
    }
};