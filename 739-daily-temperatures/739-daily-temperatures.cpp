class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size);
        stack<int>s;
        for(int i=size-1; i>=0; i--)
        {
            int wait = 0;
            while(!s.empty() && temperatures[s.top()]<=temperatures[i])
                s.pop();
            if(!s.empty())
                wait = s.top() - i;
            ans[i] = wait;
            s.push(i);
        }
        return ans;
    }
};