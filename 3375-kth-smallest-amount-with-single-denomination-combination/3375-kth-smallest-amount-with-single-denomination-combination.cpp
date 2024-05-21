class Solution {
public:
    long long gcd(long long a, long long b)
    {
        return b == 0 ? a : gcd(b,a%b);
    }
    long long lcm(long long a, long long b)
    {
        long long hcf = gcd(a,b);
        return a * b/hcf;
    }
    long long findEleSmallerThanorEqualToX(vector<int>& coins, long long X, int n)
    {
        //consider all combinations of coins
        //even combination subtracted, odd combination added
        long long m = (1<<n) - 1;
        long long count = 0;
        for(long long mask = 1; mask <=m; mask++)
        {
            long long lcmofSetBits = 1;
            long long numSetBits = 0;
            for(int j=0; j<n; j++)
            {
                if(mask&(1<<j))
                {
                    lcmofSetBits = lcm(lcmofSetBits,coins[j]);
                    numSetBits ++;
                }
            }

            if((numSetBits & 1))
                count += X / lcmofSetBits;
            else
                count -= X / lcmofSetBits;
        }
        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        //Inclusion-Exclusion Experience
        int n = coins.size();
        //maximum value : 25 * (2*1e9) ~ 1e11
        long long low = 0, high = 1e11;
        long long ans = 0;
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            long long count = findEleSmallerThanorEqualToX(coins,mid,n);
            if(count < k)
                low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
        // int n =coins.size();
        // priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // unordered_set<int>s;
        // for(int i=0; i<n; i++)
        // {
        //     pq.push({coins[i],coins[i]});
        // }
        
        // int count = 0;
        
        // int ans = INT_MAX;
        // while (!pq.empty())
        // {
        //     auto [e, step] = pq.top();
        //     pq.pop();
        //     if(s.find(e) == s.end()) {
        //         //cout<<e<<" ";
        //         s.insert(e);
        //         count ++;
        //     }
        //     if(count == k) {
        //         ans = min(ans,e);
        //         break;
        //     }
        //     if (e > ans)
        //         break;
        //     int next = e + step;
        //     int temp = pq.top().first;
        //     pq.push({next,step});
        // }
        // return ans;
    }
};