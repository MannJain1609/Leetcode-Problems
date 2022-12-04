class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum+= nums[i];
        }
        int index = 0;
        long long s = 0,abs_min = sum;
        for(int i=0; i<n; i++)
        {
            s+= nums[i];
            int x = s/(i+1);
            int y = 0;
            if(n-i-1>0)
                y = (sum - s)/(n-i-1);
            int abs_diff = x>y ? x-y : y-x;
            if(abs_diff < abs_min)
            {
                abs_min = abs_diff;
                index = i;
            }
        }
        return index;
    }
};