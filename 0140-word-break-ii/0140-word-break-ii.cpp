class Solution {
public:
    void helper(int n, vector<string>& ans, string& s, vector<string>& wordDict, int i, string temp)
    {
        if(i >= n) {
            ans.push_back(temp);
            return;
        }

        for(int j = i; j<n; j++)
        {
            string t = s.substr(i, j-i+1);
            if(find(wordDict.begin(), wordDict.end(), t) != wordDict.end()) {
                string prev = temp;
                if(temp!= "")
                    temp = temp + " " + t;
                else
                    temp = t;
                helper(n,ans,s,wordDict,j+1,temp);
                temp = prev;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string>ans;
        helper(n,ans,s,wordDict,0, "");
        return ans;
    }
};