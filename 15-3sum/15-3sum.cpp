class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<size-2; i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int start=i+1,end=size-1,target=-nums[i],prev=INT_MIN;
            while(start<end)
            {
                if(nums[start]+nums[end] == target)
                {
                    if(prev!=nums[start])
                        ans.push_back({nums[i],nums[start],nums[end]});
                    prev = nums[start];
                }
                if(nums[start]+nums[end]>target)
                    end--;
                else
                    start++;
            }
        }
        return ans;
    }
};