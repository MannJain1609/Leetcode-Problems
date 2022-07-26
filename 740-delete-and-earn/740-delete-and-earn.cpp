class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxNum = 0;
        for(int num : nums)
        {
            mp[num]+=num;
            maxNum = max(maxNum,num);
        }
        vector<int>dp(maxNum+1,0);
        //dp[i] stores maximum points from o to i
        dp[1] = mp[1];
        for(int i=2; i<=maxNum; i++)
        {
            dp[i] = max(dp[i-1], mp[i]+dp[i-2]);
        }
        return dp[maxNum];
    }
};