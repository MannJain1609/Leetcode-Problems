class Solution {
private:
    //postorder
    void dfs(vector<int>& ans, vector<vector<int>>& adj, vector<int>& count, int node, int parent)
    {
        for(int child : adj[node])
        {
            if(child!=parent)
            {
                dfs(ans,adj,count,child,node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    //preorder
    //root me ans h..baaki childs me ans daalna h
    // there are count[child] nodes that are 1 easier to get to from child than parent,
    //and N-count[child] nodes that are 1 harder to get to from child than parent.
    void dfs2(vector<int>& ans, vector<vector<int>>& adj, vector<int>& count, 
              int node, int parent, int n)
    {
        for(int child : adj[node])
        {
            if(child!=parent)
            {
                ans[child] = ans[node] - count[child] + n - count[child];
                dfs2(ans,adj,count,child,node,n);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int size = edges.size();
        //Make undirected graph through adjacency list
        vector<vector<int>> adj(n);
        for(int i=0; i<size; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>ans(n,0);
        //count is the number of nodes in the subtree including the node
        //initialising the count with 1 as counting itself
        vector<int>count(n,1);
        //apply dfs on oth node to get its answer: 0 is the root
        //ans[root] = stsum[root]
        //stsum[node]+=stsum[child] + count[child] //for every child
        dfs(ans,adj,count,0,-1);
        dfs2(ans,adj,count,0,-1,n);
        return ans;
    }
};