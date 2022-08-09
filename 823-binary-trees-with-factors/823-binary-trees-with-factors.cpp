class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(),arr.end());
        //All the values are unique
        unordered_map<int,int>index;
        for(int i=0; i<size; i++)
        {
            index[arr[i]] = i;
        }
        int MOD = 1000000007;
        vector<long long>dp(size,1);
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(arr[i]%arr[j] == 0)
                {
                    int right = arr[i] / arr[j];
                    if(index.find(right)!=index.end())
                    {
                        dp[i] = (dp[i] + dp[j] * dp[index[right]]) % MOD;
                    }
                }
            }
        }
        long long ans = 0;
        for(long long x : dp)
        {
            ans += x;
        }
        return (int)(ans%MOD);
    }
};