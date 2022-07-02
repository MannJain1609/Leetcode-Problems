class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        if(size==0 && n==1)
            return 1;
        unordered_map<int,int> mp;
        unordered_set<int> s;
        vector<int> judges;
        for(int i=0; i<size; i++) 
        {
            mp[trust[i][1]]++;
            s.insert(trust[i][0]);
            if(mp[trust[i][1]] == n-1)
                judges.push_back(trust[i][1]);
        }
        int len =judges.size();
        for(int i=0; i<len; i++)
        {
            if(s.count(judges[i])==0)
                return judges[i];
        }
        return -1;
    }
};