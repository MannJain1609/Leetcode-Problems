class Solution {
private:
    bool isSubsequence(string s, string st,int n)
    {
        int n2 = st.size();
        int i=0,j=0;
        while(i<n)
        {
            if(s[i] == st[j])
                j++;
            i++;
            if(j == n2)
                return true;
        }
        return false;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int size = words.size();
        sort(words.begin(),words.end());
        int count = 0;
        int n = s.size();
        bool prev = false;
        for(int i=0; i<size; i++)
        {
            if(i!=0 && words[i] == words[i-1]) {
                if(prev)
                    count++;
                continue;
            }
            prev = isSubsequence(s,words[i],n);
            if(prev)
                count++;
        }
        return count;
    }
};