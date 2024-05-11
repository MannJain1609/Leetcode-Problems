class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        int freq[26] = {0};
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        
        for(int i=0; i<n; i++)
        {
            pq.push({max(abs(points[i][0]), abs(points[i][1])),s[i]-'a'});
        }
        int ans = 0;
        int last = -1;
        int count = 0;
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            freq[ind]++;
            if(freq[ind] == 1)
            {
                if(last == dist)
                {
                    count++;
                }
                else {
                    count = 1;
                    last = dist;
                }
                ans++;
            }
            else {
                if(last == dist)
                    ans -= count;
                break;
            }
        }
        return ans;

        // int min_row = INT_MAX, min_col = INT_MAX;
        // unordered_map<char,vector<int>>mp;
        // int n = s.size();
        // for(int i=0; i<n; i++)
        // {
        //     mp[s[i]].push_back(i);
        // }
        // for(auto it = mp.begin(); it!=mp.end(); it++)
        // {
        //     vector<int> temp = it->second;
        //     int t = temp.size();
        //     if(t > 1)
        //     {
        //         priority_queue<int, vector<int>, greater<int>>rows;
        //         priority_queue<int,vector<int>, greater<int>>cols;
        //         for(int i=0; i<t; i++)
        //         {
        //             rows.push(abs(points[temp[i]][0]));
        //             cols.push(abs(points[temp[i]][1]));
        //         }
        //         rows.pop();
        //         cols.pop();
        //         int row = rows.top();
        //         int col = cols.top();
        //         min_row = min(min_row, row);
        //         min_col = min(min_col,col);
        //     }
        // }
        // int ans= 0;
        // for(int i=0; i<n; i++)
        // {
        //     if(abs(points[i][0]) < min_row && abs(points[i][1]) < min_col)
        //         ans++;
        // }
        // return ans;
    }
};