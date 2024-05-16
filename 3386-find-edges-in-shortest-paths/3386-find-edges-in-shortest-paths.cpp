class Solution {
public:
    // int min_dist = INT_MAX;
    // void dfs(vector<vector<pair<int,int>>>& adj, int n, vector<bool>& visited, int i, vector<vector<int>>& paths, vector<int>& temp, vector<int>& dist, int d) {
    //     if(i == n-1)
    //     {
    //         paths.push_back(temp);
    //         dist.push_back(d);
    //         min_dist = min(min_dist,d);
    //         return;
    //     }
        
    //     if(d > min_dist)
    //         return;
        
    //     visited[i] = true;
    //     for(auto node : adj[i])
    //     {
    //         if(!visited[node.first])
    //         {
    //             temp.push_back(node.first);
    //             dfs(adj,n,visited,node.first,paths,temp,dist,node.second + d);
    //             temp.pop_back();
    //         }
    //     }
    //     visited[i] = false;
    // }
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        int m = edges.size();
        for(int i=0; i<m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],i});
            adj[edges[i][1]].push_back({edges[i][0],i});
        }
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        vector<int>path(n,INT_MAX);
        path[0] = 0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto [l, u] = pq.top();
            pq.pop();

            if(l == path[u])
            {
                for(auto [v,ind]: adj[u])
                {
                    if(l + edges[ind][2] < path[v])
                    {
                        path[v] = l+edges[ind][2];
                        pq.push({path[v],v});
                    }
                }
            }
        }

        //backtrack
        pq.push({path[n-1],n-1});
        vector<bool>res(m,false);
        vector<bool>visited(n,false);

        while(!pq.empty())
        {
            auto [len, u] = pq.top();
            pq.pop();
            for(auto [v, ind] : adj[u])
            {
                if(len - edges[ind][2] == path[v])
                {
                    if(!visited[v])
                        pq.push({path[v],v});
                    res[ind] = visited[v] = true;
                }
            }
        }
        return res;

        
//         vector<bool>visited(n,false);
//         vector<vector<int>>paths;
//         vector<int>temp;
//         temp.push_back(0);
//         vector<int>dist;
//         dfs(adj,n,visited,0,paths,temp,dist,0);
//         int size = paths.size();
        
//         vector<bool>ans(m);
//         set<pair<int,int>>s;
//         for(int j=0; j<size; j++)
//         {
//             if(dist[j] == min_dist) {
//                 vector<int>& path = paths[j];
//                 int len = path.size();
//                 for(int i=1; i<len; i++)
//                 {
//                     s.insert({path[i-1], path[i]});
//                 }
//             }
//         }
//         for(int i=0; i<m; i++)
//         {
//             if(ans[i])
//                 continue;
//             if(s.find({edges[i][0], edges[i][1]}) != s.end() || s.find({edges[i][1], edges[i][0]}) != s.end())
//                 ans[i] = true;
//         }
//         return ans;
    }
};