// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
  
  bool checkCycle(int u, vector<bool>& visited, vector<int> adj[], vector<bool>& recstack) {
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
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>recstack(V,false);
        for(int i=0; i<V; i++)
        {
            if(!visited[i] && checkCycle(i,visited,adj,recstack))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends