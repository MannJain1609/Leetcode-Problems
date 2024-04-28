class Solution {
public:
    bool isPalindrome(string s) {
        cout<<"here";
        int size = s.size();
        int n = (size-1)/2;
        for(int i=0; i<=n; i++) {
            if(s[i] != s[size-i-1])
                return false;
        }
        return true;
    }
    void helper(int n, string s, int i, vector<vector<string>>& ans, vector<string>& temp) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }
        for(int len = 1; len <= n - i; len++) {
            string t = s.substr(i,len);
            if(isPalindrome(t)) {
                temp.push_back(t);
                helper(n,s,i+len,ans,temp);
                temp.pop_back();
            }
        }              
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string>temp;
        helper(n,s,0,ans,temp);
        return ans;
    }
};