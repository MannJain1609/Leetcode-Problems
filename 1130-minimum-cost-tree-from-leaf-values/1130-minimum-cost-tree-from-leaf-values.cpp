class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int size = arr.size();
        stack<int> s;
        int res = 0;
        for(int num : arr)
        {
            while(!s.empty() && s.top()<=num)
            {
                int x = s.top();
                s.pop();
                if(s.empty())
                    res+= x * num;
                else
                    res+= x * min(num,s.top());
            }
            s.push(num);
        }
        while(s.size()>1)
        {
            int x = s.top();
            s.pop();
            res+= x * s.top();
        }
        return res;
    }
};