class Solution {
    double queryAns;
public:
    bool DFS(unordered_map<string, vector<pair<double, string>>>& adj, unordered_map<string,bool>& visited, string startNode, string endNode, double runningPdt)
    {
        if(startNode == endNode && adj.find(startNode)!=adj.end())
        {
            queryAns = runningPdt;
            return true;
        }
        bool tempAns = false;
        visited[startNode] = true;
        int size = adj[startNode].size();
        for(int i=0; i<size; i++)
        {
            if(!visited[adj[startNode][i].second])
            {
                tempAns = DFS(adj,visited,adj[startNode][i].second,endNode,runningPdt*adj[startNode][i].first);
                if(tempAns)
                    break;
            }
        }
        visited[startNode] = false;
        return tempAns;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<double, string>>> adj;
        unordered_map<string,bool>visited;
        for(int i = 0; i<equations.size(); i++)
        {
            adj[equations[i][0]].push_back(make_pair(values[i], equations[i][1]));
            adj[equations[i][1]].push_back(make_pair((1/values[i]), equations[i][0]));
            visited[equations[i][0]]= false;
            visited[equations[i][1]] = false;
        }
        int m = queries.size();
        vector<double>result(m);
        for(int j=0; j<m; j++)
        {
            queryAns = 1;
            bool pathFound = DFS(adj, visited, queries[j][0], queries[j][1],1);
            if(pathFound)
                result[j] = queryAns;
            else
                result[j] = -1;
            
        }
        return result;
    }
};