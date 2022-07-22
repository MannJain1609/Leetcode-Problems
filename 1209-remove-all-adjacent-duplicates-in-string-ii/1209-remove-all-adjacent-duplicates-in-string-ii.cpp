class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char c : s)
        {
            if(!st.empty() && st.top().first == c) {
                int count = st.top().second;
                st.pop();
                if(count+1<k)
                    st.push({c,count+1});
            }
            else
                st.push({c,1});
        }
        string ans="";
        while(!st.empty())
        {
            char c = st.top().first;
            int k = st.top().second;
            st.pop();
            string x(k,c);
            ans = x+ans;
        }
        return ans;
    }
};