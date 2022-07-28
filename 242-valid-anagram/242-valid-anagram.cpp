class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(char c : s)
            mp[c]++;
        for(int i=0,n = t.size(); i<n; i++)
        {
            if(mp[t[i]]==0)
                return false;
            else if(mp[t[i]]==1)
                mp.erase(t[i]);
            else
                mp[t[i]]--;
                
        }
        return mp.empty();
    }
};