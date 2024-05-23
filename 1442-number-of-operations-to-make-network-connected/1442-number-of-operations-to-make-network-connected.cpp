class Solution {
public:
    int find_par(int x, vector<int>& parent)
    {
        if(parent[x] != x)
            return parent[x] = find_par(parent[x], parent);
        return x;
    }
    void union_find(vector<int>& parent,vector<int>& rank, int x, int y)
    {
        int xpar = find_par(x,parent);
        int ypar = find_par(y,parent);
        int xrank = rank[xpar];
        int yrank = rank[ypar];

        if(xpar == ypar)
            return;
        if(xrank > yrank)
        {
            parent[ypar] = xpar;
        }
        else if(xrank < yrank) {
            parent[xpar] = ypar;
        }
        else {
            rank[xpar]++;
            parent[ypar] = xpar;
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        if(e < n-1)
            return -1;
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        for(int i=0; i<n; i++)
            parent[i] = i;
        for(auto& c: connections)
        {
            union_find(parent,rank,c[0],c[1]);
        }
        int components = 0;
        for(int i=0; i<n; i++)
        {
            if(parent[i] == i)
                components++;
        }
        return components-1;
    }
};