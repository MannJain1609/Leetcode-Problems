class Solution {
private:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int m, int n, int i, int j)
    {
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j] || grid[i][j]==0)
            return 0;
        visited[i][j] = true;
        
        int u = dfs(grid,visited,m,n,i-1,j);
        int d = dfs(grid,visited,m,n,i+1,j);
        int l = dfs(grid,visited,m,n,i,j-1);
        int r = dfs(grid,visited,m,n,i,j+1);
        return(u+d+l+r+1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int maxArea = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1) {
                    maxArea = max(maxArea,dfs(grid,visited,m,n,i,j));
                }
            }
        }
        return maxArea;
    }
};