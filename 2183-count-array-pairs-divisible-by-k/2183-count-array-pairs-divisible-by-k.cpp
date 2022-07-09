class Solution {
private:
    int gcd(int a, int b)
    {
        return (a%b == 0) ? b : gcd(b,a%b);
    }
public:
    long long countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        long long count = 0;
        for(int i=0; i<n; i++)
        {
            int x = gcd(nums[i],k);
            int y = k/x;
            for(auto it = mp.begin(); it!=mp.end(); it++)
            {
                if(it->first % y == 0)
                    count+=it->second;
            }
            mp[x]++;
        }
        return count;
    }
};
