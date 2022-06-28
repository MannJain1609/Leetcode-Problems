class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        int i = 0;
        //swap sort
        while(i<size) {
            if(nums[nums[i]-1] != nums[i]) {
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
            else
                i++;
        }
        for(int i=0; i<size; i++)
        {
            if(nums[i]!=i+1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};