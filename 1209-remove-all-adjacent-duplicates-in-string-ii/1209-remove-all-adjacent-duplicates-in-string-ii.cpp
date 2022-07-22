class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 0;
        vector<int> count(s.size());
        for(int j=0;j<s.size();j++,i++) {
            s[i] = s[j];
            count[i] = ((i > 0 && s[i] == s[i-1]) ? count[i-1] + 1 : 1 );
            if(count[i] == k)
                i -= k;
        }
        return s.substr(0,i);
        // stack<pair<char,int>>st;
        // for(char c : s)
        // {
        //     if(!st.empty() && st.top().first == c) {
        //         int count = st.top().second;
        //         st.pop();
        //         if(count+1<k)
        //             st.push({c,count+1});
        //     }
        //     else
        //         st.push({c,1});
        // }
        // string ans="";
        // while(!st.empty())
        // {
        //     char c = st.top().first;
        //     int k = st.top().second;
        //     st.pop();
        //     string x(k,c);
        //     ans = x+ans;
        // }
        // return ans;
    }
};