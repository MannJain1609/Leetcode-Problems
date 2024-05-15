class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y < target)
            return false;
        if(x+y == target || x == target || y == target)
            return true;
        queue<int>q;
        q.push(0);
        vector<int>steps = {x,y,-x,-y};
        unordered_set<int>s;
        while(!q.empty())
        {
            int w = q.front();
            q.pop();
            for(int step : steps)
            {
                int total = w + step;
                if(total == target)
                    return true;
                if(total <= 0 || total > x+y || s.find(total) != s.end())
                    continue;
                s.insert(total);
                q.push(total);
            }
        }
        return false;
    }
};