class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int ans = 0;
        int prefix_sum = 0;
        for(int n : nums) {
            prefix_sum += n;
            if(mp.find(prefix_sum - k) != mp.end())
                ans += mp[prefix_sum - k];
            mp[prefix_sum]++;
        }
        return ans;
    }
};