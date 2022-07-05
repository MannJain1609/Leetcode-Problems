class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int index = size;
        for(int i=0; i<size; i++)
        {
            if(nums[i]>=0)
            {
                index = i;
                break;
            }
        }
        int i = index-1, j= index,k=0;
        vector<int>ans(size);
        while(i>=0 && j<size)
        {
            if(nums[i]*nums[i] > nums[j]*nums[j])
            {
                ans[k] = nums[j]*nums[j];
                j++;
            }
            else
            {
                ans[k] = nums[i] * nums[i];
                i--;
            }
            k++;
        }
        while(i>=0)
        {
            ans[k] = nums[i]*nums[i];
            i--;
            k++;
        }
        while(j<size)
        {
            ans[k] = nums[j]*nums[j];
            j++;
            k++;
        }
        return ans;
    }
};