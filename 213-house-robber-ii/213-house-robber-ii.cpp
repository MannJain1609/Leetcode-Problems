class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int dp1[size],dp2[size+1];
        if(size==1)
            return nums[0];
        //Taking the first house and neglecting the last house
        dp1[0] = 0;
        for(int i=1; i<size; i++)
        {
            if(i==1)
                dp1[i] = nums[i-1];
            else
                dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);
        }
        
        //Not taking the first house and considering the last house
        dp2[0] = 0;
        for(int i=1; i<=size; i++)
        {
            if(i==1)
                dp2[i] = 0;
            else if(i==2)
                dp2[i] = nums[i-1];
            else
                dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i-1]);
        }
        return max(dp1[size-1],dp2[size]);
    }
};