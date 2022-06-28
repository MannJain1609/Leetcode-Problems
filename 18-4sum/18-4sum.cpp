class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<size-3; i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int prev= INT_MIN;
            for(int j=i+1; j<size-2; j++)
            {
                //cout<<nums[i]<<" "<<nums[j]<<endl;
                if(j!=i+1 && prev == nums[j])
                    continue;
                prev = nums[j];
                long long tar = (long long)target-nums[i]-nums[j];
                int start = j+1,end = size-1,prev2 = INT_MIN;
                while(start<end)
                {
                    if((long long)nums[start]+nums[end]==tar)
                    {
                        if(start==j+1 || prev2!=nums[start])
                            ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        prev2 = nums[start];
                    }
                    if((long long)nums[start]+nums[end]>tar)
                        end--;
                    else
                        start++;
                }
            }
        }
        return ans;
    }
};