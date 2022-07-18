class Solution {
private:
    unordered_map<string,bool>mp;
    bool solve(string s1,string s2) {
        //if size is not equal, they are not scrambled
        int n = s1.size();
        int m = s2.size();
        if(n!=m)
            return false;
        if(s1 == s2)
            return true;
        //size 1 and not equal, not scramble
        if(n == 1)
            return false;
        string key = s1 + " "+ s2;
        //memoization
        if(mp.find(key)!=mp.end())
            return mp[key];
        //as we cannot do the case for less than 1, not considering n 
        
        for(int len = 1; len<n; len++)
        {
            //without swap
            //comapring both left and right parts
            bool withoutSwap = solve(s1.substr(0,len),s2.substr(0,len)) &&
                            solve(s1.substr(len),s2.substr(len));
            if(withoutSwap)
                return true;
            
            //with swap
            //comparing left with right and right with left
            bool withSwap = solve(s1.substr(0,len),s2.substr(n-len)) &&
                            solve(s1.substr(len),s2.substr(0,n-len));
            if(withSwap)
                return true;
        }
        //handling for next breaks
        return mp[key] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};