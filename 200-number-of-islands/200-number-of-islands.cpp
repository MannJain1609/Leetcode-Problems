// class grid_dim {
// public:
//     int val,row,col;
//     grid_dim(int val, int row, int col) {
//         this->val = val;
//         this->row = row;
//         this->col = col;
//     }
// };
class Solution {
private:
    void bfs(vector<vector<char>>& grid, int row, int col, int m, int n) {
        //queue<grid_dim> q;
        //visited[row][col] = true;
        //q.push({grid[row][col],row,col});
        grid[row][col] = '.';
        if(row>0 && grid[row-1][col] == '1')
            bfs(grid,row-1,col,m,n);
        if(row+1<m && grid[row+1][col]=='1')
            bfs(grid,row+1,col,m,n);
        if(col>0 && grid[row][col-1]=='1')
            bfs(grid,row,col-1,m,n);
        if(col+1<n && grid[row][col+1]=='1')
            bfs(grid,row,col+1,m,n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        //vector<vector<bool>>visited(m, vector<bool> (n,false));
        int count = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1') {
                    bfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};