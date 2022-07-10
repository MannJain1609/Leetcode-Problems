class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++)
            sum+=nums[i];
        if(target+sum<0 || (target+sum)&1)
            return 0;
        int t = (target+sum)/2;
        
        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        for(int i =0; i<=n; i++)
        {
            for(int j=0; j<=t; j++)
            {
                if(j==0 && i==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                else if(j==0)
                {
                    dp[i][j] = dp[i-1][j];
                    if(nums[i-1]==0)
                        dp[i][j]+=dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                    if(j-nums[i-1]>=0)
                        dp[i][j]+=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][t];
    }
};