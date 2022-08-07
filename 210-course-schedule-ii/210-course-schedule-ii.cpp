class Solution {
private:
    bool hasCycle(int u, vector<int> adj[], vector<bool>& visited,vector<bool>& recStack)
    {
        visited[u] = true;
        recStack[u] = true;
        for(int v : adj[u])
        {
            if(!visited[v] && hasCycle(v,adj,visited,recStack))
                return true;
            else if(recStack[v])
                return true;
        }
        recStack[u] = false;
        return false;
    }
    void dfs(int u, vector<int> adj[], vector<bool>& visited,stack<int>& st)
    {
        visited[u] = true;
        for(int v: adj[u])
        {
            if(!visited[v])
                dfs(v,adj,visited,st);
        }
        st.push(u);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int> adj[numCourses];
        int size = prerequisites.size();
        for(int i=0; i<size; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>recStack(numCourses,false);
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                if(hasCycle(i,adj,visited,recStack)) {
                    //cout<<"h";
                    return ans;
                }
            }
        }
        for(int i=0; i<numCourses; i++)
            visited[i] = false;
        stack<int>st;
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
                dfs(i,adj,visited,st);
        }
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            ans.push_back(u);
        }
        return ans;
    }
};