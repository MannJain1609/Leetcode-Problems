class Solution {
private:
    int dfs(int u, vector<int> adj[], vector<int>& informTime) {
        int mx = 0;
        for(int v : adj[u])
        {
            mx = max(mx,dfs(v,adj,informTime));
        }
        return informTime[u] + mx;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0; i<n; i++)
        {
            if(i == headID)
                continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(headID,adj,informTime);
    }
};