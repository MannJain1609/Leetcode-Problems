class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftSmallerIndex(n,-1);
        vector<int>rightSmallerIndex(n,n);
        stack<int>s;
        s.push(0);
        for(int i=1; i<n; i++)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(!s.empty())
                leftSmallerIndex[i] = s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        s.push(n-1);
        for(int i=n-2; i>=0; i--)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(!s.empty())
                rightSmallerIndex[i] = s.top();
            s.push(i);
        }

        int area = 0;
        for(int i=0; i<n; i++)
        {
            int left_ind = leftSmallerIndex[i];
            int right_ind = rightSmallerIndex[i];
            area = max(area, (right_ind - left_ind - 1) * heights[i]);
        }
        return area;
    }
};