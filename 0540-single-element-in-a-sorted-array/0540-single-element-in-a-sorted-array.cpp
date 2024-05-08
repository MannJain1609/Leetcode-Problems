class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low < high)
        {
            int mid = (low+high)/2;
            if(nums[low] != nums[low+1])
                return nums[low];
            if(nums[high] != nums[high-1])
                return nums[high];
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
              return nums[mid];
            low+=2;
            high-=2;
        }
        return nums[low];
    }
};