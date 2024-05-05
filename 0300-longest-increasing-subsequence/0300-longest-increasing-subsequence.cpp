class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int>dp(size,0);
        int ans = 1;
        for(int i=0; i<size; i++) {
            dp[i] = 1;
            for(int prev = 0; prev<i; prev++) {
                if(nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};