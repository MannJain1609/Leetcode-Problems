class TreeAncestor {
public:
    int maxPower;
    vector<vector<int>>dp;
    TreeAncestor(int n, vector<int>& parent) {
        this->maxPower = (int)log2(n) + 1;
        dp.resize(maxPower,vector<int>(n));
        dp[0] = parent;
        for(int i=1; i<maxPower; i++)
        {
            for(int j=0; j<n; j++)
            {
                int prev_ancestor = dp[i-1][j];
                if(prev_ancestor == -1)
                    dp[i][j] = -1;
                else
                {
                    dp[i][j] = dp[i-1][prev_ancestor];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int currPower = maxPower - 1;
        while(k >0 && node!=-1)
        {
            if(k >= (1<<currPower)) {
                node = dp[currPower][node];
                k -= (1<<currPower);
            }
            currPower--;
        }
        return node;
    }
    
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */