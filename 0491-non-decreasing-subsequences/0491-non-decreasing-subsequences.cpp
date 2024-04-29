class Solution {
public:
    void helper(set<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int n, int i) {
        if(i == n) {
            if(temp.size() >= 2)
                ans.insert(temp);
            return;
        }
        //cout<<"init "<<i<<endl;
        int size = temp.size();
        if(size == 0 || temp[size-1] <= nums[i])
        {
            temp.push_back(nums[i]);
            helper(ans,temp,nums,n,i+1);
            temp.pop_back();
        }
        helper(ans,temp,nums,n,i+1);
        //cout<<"end "<<i<<endl;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>s;
        vector<int>temp;
        int n = nums.size();
        helper(s,temp,nums,n,0);
        for(vector<int> x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};