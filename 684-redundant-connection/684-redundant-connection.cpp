class Solution {
private:
    class DisjointSet {
    public:
        int n;
        vector<int> parent;
        vector<int>rank;
        
        DisjointSet(int n) {
            this->n = n;
            parent.resize(n+1);
            rank.resize(n+1);
        }
        
        void makeset() {
            for(int i=0; i<=n; i++) {
                parent[i] = -1;
                rank[i] = 0;
            }
        }
        
        int find(int x)
        {
            if(parent[x] == -1)
                return x;
            return parent[x] = find(parent[x]);
        }
        
        bool union_find(int x, int y) {
            int parent_x = find(x);
            int parent_y = find(y);
            int rank_x = rank[parent_x];
            int rank_y = rank[parent_y];
            
            if(parent_x == parent_y)
                return false;
            
            if(rank_x > rank_y)
                parent[parent_y] = parent_x;
            else if(rank_y > rank_x)
                parent[parent_x] = parent_y;
            else
            {
                parent[parent_y] = parent_x;
                rank[parent_x]++;
            }
            return true;
        }
    };
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        DisjointSet ds(n);
        ds.makeset();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++)
        {
            if(!ds.union_find(edges[i][0],edges[i][1]))
                ans.push_back({edges[i][0],edges[i][1]});
        }
        return ans[ans.size()-1];
    }
};