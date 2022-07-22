class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int size = s.size();
        for(int i=0; i<size; i++)
        {
            if(!st.empty() && st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};