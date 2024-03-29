class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int size = queries.size();
        int n = nums.size();
        int sum = 0;
        vector<int> ans(size);
        
        for(int i=0; i<n; i++)
        {
            if((nums[i]%2) == 0)
                sum+= nums[i];
        }
        for(int i=0; i<size; i++)
        {
            const int ind = queries[i][1];
            const int val = queries[i][0];
            if((nums[ind]%2) == 0)
                sum-= nums[ind];
            nums[ind]+= val;
            if((nums[ind]%2) == 0)
                sum+= nums[ind];
            ans[i] = sum;
        }
        return ans;
    }
};