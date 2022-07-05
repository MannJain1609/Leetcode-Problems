class Solution {
private:
    bool checkCycle(int u, vector<bool>& visited, vector<vector<int>>& adj, 
                    vector<bool>& recstack) {
      visited[u] = true;
      recstack[u] = true;
      for(auto it = adj[u].begin(); it!=adj[u].end(); it++)
      {
          if(!visited[*it] && checkCycle(*it,visited,adj,recstack))
            return true;
          else if(recstack[*it])
            return true;
      }
      recstack[u] = false;
      return false;
  }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        int size = prerequisites.size();
        for(int i=0; i<size; i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(n,false);
        vector<bool> recstack(n,false);
        for(int i=0; i<n; i++)
        {
            if(!visited[i] && checkCycle(i,visited,adj,recstack))
                return false;
        }
        return true;
    }
};