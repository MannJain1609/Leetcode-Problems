class Solution {
public:
    int romanToInt(string s) {
       int n = s.size();
       int i=0;
       unordered_map<char,int>mp = {{'I',1}, {'V', 5}, {'X', 10}, {'L',50}, {'C',100}, {'D', 500}, {'M',1000}};
       int ans = 0;
       while(i < n) {
        if(i!=n-1) {
            if(mp[s[i]] < mp[s[i+1]]) {
                int temp = mp[s[i+1]] - mp[s[i]];
                ans += temp;
                i++;
            }
            else {
                ans += mp[s[i]];
            }
        }
        else 
            ans += mp[s[i]];
        i++;
       }
    return ans; 
    }
};