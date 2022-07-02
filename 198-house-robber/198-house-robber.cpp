class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int dp[size+1];
        dp[0] = 0;
        for(int i=1; i<=size; i++)
        {
            if(i==1)
                dp[i] = nums[i-1];
            else if(i==2)
                dp[i] = max(nums[i-1], dp[i-1]);
            else
                dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[size];
    }
};