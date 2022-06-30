class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        //we can take any mid value in even case, results in the same answer
        int mid = (size-1)/2;   //(size/2) will also works
        int median = nums[mid];
        int ans = 0;
        for(int i=0; i<size; i++)
        {
            ans+= abs(nums[i]-median);
        }
        return ans;
    }
};