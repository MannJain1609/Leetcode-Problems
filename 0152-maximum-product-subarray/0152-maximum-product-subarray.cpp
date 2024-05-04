class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int maxPdt = INT_MIN;
        vector<vector<int>>dp(size+1,vector<int>(2,0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i=1; i<=size; i++) {
            dp[i][0] = max(nums[i-1], max(dp[i-1][0] * nums[i-1],dp[i-1][1] * nums[i-1]));
            dp[i][1] = min(nums[i-1],min(dp[i-1][0] * nums[i-1],dp[i-1][1] * nums[i-1]));
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            maxPdt = max(maxPdt,max(dp[i][0],dp[i][1]));
        }
        return maxPdt;
    }
  
};