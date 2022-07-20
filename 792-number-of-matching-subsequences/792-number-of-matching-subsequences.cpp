class Solution {
    public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        const int n = s.length();
        unordered_map<string,int> umap;
        for(string temp : words){
            umap[temp]++;
        }
        for(auto it : umap){
            bool check = solve(s, (string)it.first);
            
            if(check) ans+=it.second;
        }
        return ans;
    }
private:
    int solve(string s1, string s2){
        const int n = s1.length();
        const int m = s2.length();
        int i=0, j=0;
        while(i<n && j<m){
            if(s1[i] == s2[j]) j++;
            i++;
        }
        return j == m;
    }
};
// private:
//     bool isSubsequence(string s, string st,int n)
//     {
//         int n2 = st.size();
//         int i=0,j=0;
//         while(i<n)
//         {
//             if(s[i] == st[j])
//                 j++;
//             i++;
//             if(j == n2)
//                 return true;
//         }
//         return false;
//     }
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int size = words.size();
//         sort(words.begin(),words.end());
//         int count = 0;
//         int n = s.size();
//         bool prev = false;
//         for(int i=0; i<size; i++)
//         {
//             if(i!=0 && words[i] == words[i-1]) {
//                 if(prev)
//                     count++;
//                 continue;
//             }
//             prev = isSubsequence(s,words[i],n);
//             if(prev)
//                 count++;
//         }
//         return count;
//     }
//};