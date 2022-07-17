class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>>p(n,vector<bool>(n,false));
        for(int i=n-1; i>=0; i--)
        {
            for(int j = i; j<n; j++)
            {
                if(i==j)
                    p[i][j]=true;
                else if(j==i+1 && s[i]==s[j])
                    p[i][j] = true;
                else if(s[i]==s[j])
                    p[i][j] = p[i+1][j-1];
            }
        }
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                if(p[0][i] && p[i+1][j] && p[j+1][n-1])
                    return true;
            }
        }
        return false;
    }
};