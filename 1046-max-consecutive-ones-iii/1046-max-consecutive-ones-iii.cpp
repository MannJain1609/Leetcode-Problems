class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //Sliding Window
        int n = nums.size();
        int i =0;
        for(int j=0; j<n; j++) {
            if(nums[j] == 0)
                k--;
            if(k<0) {
                if(nums[i] == 0)
                    k++;
                i++;
            }
        }
        return n - i;
    }
};