class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxlen = 0;
        int i=0, j=0;
        int n = s.size();
        while(j<n) {
            mp[s[j]]++;
            while(mp[s[j]] > 1) {
                mp[s[i]]--;
                i++;
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};