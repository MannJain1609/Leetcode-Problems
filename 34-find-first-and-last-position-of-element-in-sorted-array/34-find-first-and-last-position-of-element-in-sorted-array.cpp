class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int low = 0;
        int high = nums.size()-1;
        int first_ind = -1, second_ind=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
            {
                if(mid==0 || nums[mid-1]!=target)
                {
                    first_ind=mid;
                    break;
                }
                else
                    high = mid-1;
            }
            else if(nums[mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        low=0;
        high=nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
            {
                if(mid==nums.size()-1 || nums[mid+1]!=target)
                {
                    second_ind=mid;
                    break;
                }
                else
                    low = mid+1;
            }
            else if(nums[mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        ans.push_back(first_ind);
        ans.push_back(second_ind);
        return ans;
    }
};