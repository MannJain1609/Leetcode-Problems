class TreeAncestor {
public:
    //Binary Lifting
    vector<vector<int>> dp;
    int maxPower;
    TreeAncestor(int n, vector<int>& parent) {
        this->maxPower = (int)log2(n) + 1;
        dp.resize(maxPower, vector<int>(n));
        //dp[i][j] represents 2^ith ancestor of j
        //dp[0][j] resents 1st ancestor of j
        //dp[1][j] represents second(2^1) ancestor of j
        //1st ancestor of every node is given parent array
        dp[0] = parent;
        for(int i=1; i<maxPower; i++)
        {
            for(int j=0; j<n; j++)
            {
                int prev_ancestor = dp[i-1][j];
                
                if(prev_ancestor == -1)
                    dp[i][j] = -1;
                else
                    // 2^i = 2^(i-1) + 2^(i-1)
                    // Say 2^(i-1) th parent of j is FATHER
                    // Then 2^ith parent  of j will be 2^(i-1) th parent of FATHER
                    // i.e Ancestor(j,2^i) = Ancestor( Ancestor(j,2^i-1), 2^i-1)
                    dp[i][j] = dp[i-1][prev_ancestor];
            }
        }
        // v.resize(n);
        // int k = 1;
        // while(k<=n)
        // {
        //     for(int i=0; i<n; i++)
        //     {
        //         if(k > i)
        //             continue;
        //         int size = v[i].size();
        //         if(k == 1)
        //             v[i].push_back(parent[i]);
        //         else
        //         {
        //             if (v[i][size-1] == 0)
        //                 continue;
        //             v[i].push_back(parent[v[i][size-1]]);
        //         }
        //     }
        //     k++;
        // }
    }
    
    int getKthAncestor(int node, int k) {
        //nearest power of 2 to the number
        int currPower = maxPower - 1;
        while(k>0 && node!=-1)
        {
            // Move to node ancestors in steps of binary notation of k
            // Ex - 13 i.e 1101 i.e first go to 8th ancestor then 4th and then first
            // In steps of 2^currPower, 2^(currPower-1) and so on...
            if(k >= (1<<currPower))
            {
                node = dp[currPower][node];
                k-= 1<<currPower;
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