class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool>dp(size,false);
        dp[size-1] = true;
        for(int i=size-2; i>=0; i--)
        {
            int jump = nums[i];
            if(jump+i>=size-1)
                dp[i] = true;
            else
            {
                for(int j= jump; j>0; j--)
                {
                    if(!dp[i])
                        dp[i] = dp[i+j];
                    else 
                        break;
                }
            }
        }
        return dp[0];
    }
};