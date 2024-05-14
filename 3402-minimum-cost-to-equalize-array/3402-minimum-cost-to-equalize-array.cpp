const int MOD = 1e9+7;
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        //Solution 
        //Treat all the nums elements as bar, and find the gap from the maximum bar
        //ex. (4,1) -> bars of 4 and 1, gaps of 0 and 3.

        //In case when n = 2, we have to do cost1 operation on the minimum bar to equalize it to maximum
        //Else we would always be incrementing both, and the gap will remain consistent, no point in pairing

        //In case when 2*cost1 < cost2, it is more profitable to do single operations than pair operations
        //In this case, we would find the total gaps and multiply it by cost 1. (make all elements equal to max element)

        //In Case, when the maximum gap which is max(nums){calling it maxE} - min(nums){calling it minE} is greater than the sum of other gaps,
        //we cannot always pair the maximum gap, there would be some requirement of cost1.
        //we would pair the other gaps with the maximum gap for maximum cost 2 operations and the remaining would be cost1 operations
        //so, total possible gaps that cannot be paired = (maximum_gap) - (total_gaps - maximum_gap) -> 2 * (maximum_gap) - total_gaps -> (2*(maxE - minE) - total_gaps)
        //we call 2*(maxE-minE) - total_gaps as op1
        //so, gaps remaining for cost2 are op2 = total_gaps - op1
        //gaps for cost2 would be half of op2 -> op2/2
        //here, making all elemnts equal to max element

        //In case, when the maximum gap (maxE - minE) is less than or equal to the sum of the other gaps, we can make the pair of the gaps
        //if the total_gaps is even, there is no need for cost1
        //if the total_gaps is odd, there will be one gap remaining for cost1
        //here, we may equalize the array to a larger number than maxE
        //so, operations for cost1 = (total_gaps%2)
        //operations for cost2 = calculated later
        
        //if we combine the last two cases, we get
        //op1 = max(0, 2*(maxE - minE)-total_gaps)
        //op2 = total_gaps - op1
        //cost = (op1 + op2%2) * cost1 + (op2/2)*cost2;

        //now to calculate the cost2 operations to go beyond the max
        //we maintain an array to store the frequency of different gaps
        //Each time, we select two maximum gaps, and make them pair
        //at the end we would remain with only one element with freq>0
        //if the freq is even, make pairs of those gaps for cost2
        //if the freq is odd, make pairs of freq-1 gaps for cost2
        //Now, one gap will remain, now we can  extend our equalizer to go beyond  the max
        //we will add (n-2) to the index 1, as every other element will be incremented by 1 gap
        //n gaps of one are added to each index, freq(1) -> n-1 && freq(curr_idx+1) -> 1, finally after pairing, we would have (n-1) gaps of freq 1.
        //so 1 was already at index 1, we add (n-2) to make it (n-1)
        //we would do this (n-2) until we have one one or zero gaps of size 1.
        //total_gaps + =(op1/(n-2)) * n
        //remaining for op1 = op1 % (n-2)
        //op2 = total_gaps - op1
        //truy adding 1 twice to cover the case fully of cost2 

        
        int n = nums.size();
        int maxE = 0, minE = INT_MAX;
        long long total_gaps = 0;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            maxE = max(maxE, nums[i]);
            minE = min(minE, nums[i]);
            sum += nums[i];
        }
        //total_gaps = sum of (max - nums[i]) for all i ~ (max * n - sum)
        total_gaps = (long long)maxE * n - sum;
        
        if(n <=2 || 2 * cost1 <= cost2)
        {
            int minCost = (total_gaps * cost1)%MOD;
            return minCost;
        }

        long long op1 = max((long long)0, (long long)2 * (maxE - minE) - total_gaps);
        long long op2 = total_gaps - op1;
        long long res = (op1 + op2%2) * cost1 + (op2/2) * cost2;

        total_gaps += op1 / (n-2) * n;
        op1 %= (n-2);
        op2 = total_gaps - op1;
        res = min(res, (op1 + op2%2)*cost1 + (op2/2)*cost2);

        for(int i=0 ; i<2; i++)
        {
            total_gaps += n;
            res = min(res, (total_gaps%2) * cost1 + total_gaps/2 * cost2);
        }

        int ans = (int)(res % MOD);
        return ans;


        //Attempt 1: Wrong Solution (always not equalize to max, can be greater than that)
        // int maxNum = 0;
        // for(int num: nums)
        // {
        //     maxNum = max(maxNum, num);
        // }
        // int n = nums.size();
        // long long total_ops_req = 0;
        // priority_queue<long long>pq;
        // for(int i=0; i<n; i++)
        // {
        //     long long diff = (long long)maxNum - nums[i];
        //     pq.push(diff);
        //     total_ops_req += diff;
            
        // }
        // int ans= 0;
        // long long cost = 0;
        // if(cost1 * 2 <= cost2) {
        //     cost = cost1 * (total_ops_req) % MOD;
        //     ans = cost%MOD;
        // }
        // else {
        //     while(pq.size() >= 2)
        //     {
        //         long long p1 = pq.top();
        //         pq.pop();
        //         long long p2 = pq.top();
        //         pq.pop();
        //         if(p1 == p2)
        //             cost += p1 * cost2;
        //         else {
        //             cost += p2 * cost2;
        //             pq.push(p1 - p2);
        //         }
        //     }
        //     if(!pq.empty()) {
        //         cost += cost1 * pq.top();
        //     }
        //     ans = cost%MOD;
        // }
        
        // return ans;
    }
};