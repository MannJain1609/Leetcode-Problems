class Solution {
public:
    static bool cmp(vector<int> &a, vector<int>& b)
    {
        if(a[0]!=b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int numWeak = 0;
        int size = properties.size();
        sort(properties.begin(),properties.end(),cmp);
        unordered_map<int,int>mp;
        stack<int>s;
        for(int i=size-1; i>=0; i--)
        {
            while(!s.empty() && properties[s.top()][1] <= properties[i][1])
                s.pop();
            if(s.empty())
                mp[i] = -1;
            else
                mp[i] = s.top();
            s.push(i);
        }
        int count = 0;
        for(int i=0; i<size; i++)
        {
            if(mp[i]!=-1)
                count++;
        }
        return count;
      
    }
};