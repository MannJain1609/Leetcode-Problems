class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int size = points.size();
        priority_queue<pair<int,int>>pq;
        int max_val = INT_MIN;
        for(int i=0; i<size; i++)
        {
            while(!pq.empty() && points[i][0]-pq.top().second > k)
                pq.pop();
            if(!pq.empty())
            {
                max_val = max(max_val, points[i][0]+points[i][1]+pq.top().first);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return max_val;
    }
};