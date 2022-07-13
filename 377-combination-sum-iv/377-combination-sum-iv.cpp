class Solution {
private:
    int helper(vector<int>& nums, int target, int n,vector<int>& memo) {
        if(target<0)
            return 0;
        if(target == 0) {
            return 1;
        }
        if(memo[target]!=-1)
            return memo[target];
        int count = 0;
        for(int i=0; i<n; i++)
        {
            count+= helper(nums,target-nums[i],n,memo);
        }
        return memo[target]= count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>memo(target+1,-1);
        memo[0] = 1;
        return helper(nums,target,n,memo);
    }
};