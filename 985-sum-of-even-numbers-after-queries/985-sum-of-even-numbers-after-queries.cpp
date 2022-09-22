class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int size = queries.size();
        int n = nums.size();
        int sum = 0;
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            if((nums[i]&1) == 0)
                sum+= nums[i];
        }
        for(int i=0; i<size; i++)
        {
            int ind = queries[i][1];
            int val = queries[i][0];
            if((nums[ind]&1) == 0)
                sum-= nums[ind];
            nums[ind]+= val;
            if((nums[ind]&1) == 0)
                sum+= nums[ind];
            ans.push_back(sum);
        }
        return ans;
    }
};