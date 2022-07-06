class Solution {
private:
    int node_visited;
    void dfs(vector<bool>& visited, vector<vector<int>>& adj, int u)
    {
        visited[u] = true;
        node_visited++;
        
        for(auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(!visited[*it])
                dfs(visited,adj,*it);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(size<n-1)
            return -1;
        vector<vector<int>> adj(n);
        for(int i=0; i<size; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>visited(n,false);
        int min_cables = 0,count=0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                node_visited = 0;
                dfs(visited,adj,i);
                //cout<<i<<endl;
                min_cables+=node_visited-1;
                count++;
            }
        }
        int rem_cables = size - min_cables;
        if(rem_cables < count-1)
            return -1;
        return count-1;
    }
};