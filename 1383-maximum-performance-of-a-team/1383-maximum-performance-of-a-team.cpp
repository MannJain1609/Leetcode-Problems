class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> engineers;
        for(int i=0; i<n; i++)
        {
            engineers.push_back({efficiency[i],speed[i]});
        }
        sort(engineers.rbegin(), engineers.rend());
        //Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        long long speed_sum = 0;
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            speed_sum+= engineers[i][1];
            pq.emplace(engineers[i][1]);
            if(pq.size() > k)
            {
                speed_sum -= pq.top();
                // if(pq.top() == engineers[i][1])
                // {
                //     pq.pop();
                //     continue;
                // }
                pq.pop();
            }
            //in case if the current element gets pop, then it will not e the ans 
            //maximum will be the previous one.
            ans = max(ans, speed_sum*engineers[i][0]);
        }
        return ans%(1000000007);
        
    }
};