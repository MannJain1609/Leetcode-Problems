class Solution {
private:
    // bool isSafe(vector<vector<int>>& graph, int u,int n) {
    //     vector<bool>visited(n,false);
    //     queue<int>q;
    //     visited[u] = true;
    //     q.push(u);
    //     while(!q.empty())
    //     {
    //         int flag = 0;
    //         int v = q.front();
    //         q.pop();
    //         for(int x : graph[v])
    //         {
    //             if(!visited[x]) {
    //                 q.push(x);
    //                 visited[x] = true;
    //             }
    //             else 
    //                 flag = 1;
    //         }
    //         if(flag)
    //             return false;
    //     }
    //     return true;
    // }
    
    bool dfs(vector<bool>& visited, vector<bool>& safe, vector<bool>& recStack,
             vector<vector<int>>& graph, int u) {
        visited[u] = true;
        recStack[u] = true;
        for(int v : graph[u])
        {
            if(!visited[v]){
                if(!dfs(visited,safe,recStack,graph,v)) {
                    safe[u] = false;
                    safe[v] = false;
                    return false;
                }
            }
            else if(recStack[v]) {
                return false;
            }
        }
        recStack[u] = false;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<bool> visited(n,false);
        vector<bool> safe(n, true);
        vector<bool>recStack(n,false);
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                safe[i] = dfs(visited,safe,recStack,graph,i);
        }
        for(int i=0; i<n; i++)
        {
            if(safe[i])
                ans.push_back(i);
        }
        return ans;
        // for(int i=0; i<n; i++)
        // {
        //     if(isSafe(graph,i,n))
        //         ans.push_back(i);
        // }
        return ans;
    }
};