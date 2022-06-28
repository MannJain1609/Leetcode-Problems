class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //Brute Force: Gives TLE
        
        // int size = nums.size();
        // vector<int> prefix_sum(size,0);
        // prefix_sum[0] = nums[0];
        // for(int i=1; i<size; i++)
        // {
        //     prefix_sum[i] = nums[i]+prefix_sum[i-1];
        // }
        // int sum = 0,count = 0;
        // for(int i=0; i<size; i++)
        // {
        //     for(int j=i; j<size; j++)
        //     {
        //         if(i==0)
        //             sum = prefix_sum[j];
        //         else
        //             sum = prefix_sum[j]-prefix_sum[i-1];
        //         if(sum%k == 0)
        //             count++;
        //     }
        // }
        // return count;
        
        //Optimized using hashmap
        int size = nums.size(),currSum = 0;
        int count = 0;
        unordered_map<int,int>r;
        for(int i=0; i<size; i++)
        {
            currSum+=nums[i];
            //to handle negative numbers
            int rem = (currSum%k+k)%k;
            if(rem == 0)
                count++;
            count+= r[rem];
            r[rem]++;
        }
        return count;
    }
};