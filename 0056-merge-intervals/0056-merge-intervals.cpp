class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int prev = -1;
        int n = intervals.size();
        for(int i=0; i<n; i++)
        {
            if(intervals[i][0] <= prev) {
                vector<int> temp = ans.back();
                ans.pop_back();
                temp[1] = max(intervals[i][1],temp[1]);
                ans.push_back(temp);
                prev = temp[1];
            }
            else {
                ans.push_back(intervals[i]);
                prev = intervals[i][1];
            }
        }
        return ans;
    }
};