class Solution {
private:
    bool isPalindrome(string str)
    {
        int size = str.size();
        int x = size/2;
        for(int i=0; i<x; i++)
        {
            if(str[i]!=str[size-i-1])
                return false;
        }
        return true;
    }
    void helper(int n, string s, vector<vector<string>>& ans, vector<string>& v, int index)
    {
        if (index==n) {
            ans.push_back(v);
            return;
        }
        
        string str = "";
        for (int i=index;i<n;i++) {
            str+=s[i];
            if (isPalindrome(str)) {
                v.push_back(str);
                helper(n,s,ans,v,i+1);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>v;
        helper(n,s,ans,v,0);
        return ans;
    }
};