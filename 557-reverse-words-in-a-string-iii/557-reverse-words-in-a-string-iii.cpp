class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string tokens;
        stringstream check(s);
        while(getline(check,tokens,' '))
        {
            reverse(tokens.begin(),tokens.end());
            ans+= tokens + " ";
        }
        ans.resize(ans.size()-1);
        return ans;
    }
};