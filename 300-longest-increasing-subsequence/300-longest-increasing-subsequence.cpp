class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        int size= nums.size();
        temp.push_back(nums[0]);
        for(int i=1; i<size; i++)
        {
            if(nums[i]>temp.back())
                temp.push_back(nums[i]);
            else
            {
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return temp.size();
    }
};