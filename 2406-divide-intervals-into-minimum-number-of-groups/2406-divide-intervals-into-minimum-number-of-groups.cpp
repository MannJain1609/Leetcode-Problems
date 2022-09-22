class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int groups = 1;
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(intervals[0][1]);
        for(int i=1; i<n; i++)
        {
            int num = intervals[i][0];
            if(num > pq.top())
            {
                int x = pq.top();
                pq.pop();
                pq.push(max(x,intervals[i][1]));
            }
            else
            {
                groups++;
                pq.push(intervals[i][1]);
            }
            // while(j<size)
            // {
            //     int x = s.front();
            //     if(num > x)
            //     {
            //         s.pop();
            //         s.push(max(intervals[i][1],x));
            //         flag = 1;
            //         break;
            //     }
            //     s.pop();
            //     s.push(x);
            //     j++;
            // }
            
        }
        return groups;
    }
};