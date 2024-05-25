class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>ind;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] == x)
                ind.push_back(i);
        }
        int m = queries.size();
        int t = ind.size();
        vector<int>ans(m,-1);
        if(t == 0)
            return ans;
        for(int i=0; i<m; i++)
        {
            if(queries[i] > t)
                continue;
            ans[i] = ind[queries[i] - 1];
        }
        return ans;
    }
};