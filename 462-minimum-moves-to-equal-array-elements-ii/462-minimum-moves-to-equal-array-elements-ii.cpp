class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int mid = size/2;
        int median = nums[mid];
        int ans = 0,x = 0;
        for(int i=0; i<size; i++)
        {
            ans+= abs(nums[i]-median);
        }
        if(size%2==0)
        {
            int mid_val = nums[mid-1],x=0;
            for(int i=0; i<size; i++)
            {
                x+=abs(nums[i]-mid_val);
            }
            ans = min(ans,x);
        }
        return ans;
    }
};