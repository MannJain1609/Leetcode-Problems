class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size==1)
            return 0;
        int low=0,high=size-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mid==0) {
                if(nums[mid]>nums[mid+1])
                    return mid;
                low = mid+1;
            }
            else if(mid == size-1) {
                if(nums[mid]>nums[mid-1])
                    return mid;
                high = mid-1;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid] < nums[mid-1])
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
};