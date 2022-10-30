class Solution {
private:
    //int min_steps = INT_MAX;
    //void helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int k, int m, int n, 
    //             int row, int col, int count)
    // {
    //     if(row<0 || col<0 || row>=m || col>=n || visited[row][col])
    //         return;
    //     if(row==m-1 && col == n-1)
    //     {
    //         min_steps = min(min_steps,count);
    //         return;
    //     }
    //     visited[row][col] = true;
    //     //up
    //     if(row-1>=0 && !visited[row-1][col])
    //     {
    //         if(grid[row-1][col]==1 && k>0)
    //             helper(grid,visited,k-1,m,n,row-1,col,count+1);
    //         else if(grid[row-1][col]==0)
    //             helper(grid,visited,k,m,n,row,col,count+1);
    //     }
    //     //down
    //     if(row+1<m && !visited[row+1][col])
    //     {
    //         if(grid[row+1][col]==1 && k>0)
    //             helper(grid,visited,k-1,m,n,row+1,col,count+1);
    //         else if(grid[row+1][col]==0)
    //             helper(grid,visited,k,m,n,row+1,col,count+1);
    //     }
    //     //left
    //     if(col-1>=0 && !visited[row][col-1])
    //     {
    //         if(grid[row][col-1]==1 && k>0)
    //             helper(grid,visited,k-1,m,n,row,col-1,count+1);
    //         else if(grid[row][col-1]==0)
    //             helper(grid,visited,k,m,n,row,col-1,count+1);
    //     }
    //     //right
    //     if(col+1<n && !visited[row][col+1])
    //     {
    //         if(grid[row][col+1]==1 && k>0)
    //             helper(grid,visited,k-1,m,n,row,col+1,count+1);
    //         else if(grid[row][col+1]==0)
    //             helper(grid,visited,k,m,n,row,col+1,count+1);
    //     }
    //     visited[row][col] = false;
    // }
    class Cell {
        public:
        int row,col,used_lives,steps;
        Cell(int row, int col, int used_lives, int steps) {
            this->row = row;
            this->col = col;
            this->used_lives = used_lives;
            this->steps = steps;
        }
    };
    
    bool isPossible(int row,int col,int m, int n)
    {
        if(row<0 || col<0 || row>=m || col>=n)
            return false;
        return true;
    }
    int bfs(vector<vector<int>>& grid, int k, vector<vector<int>>& obstacles,  
            vector<vector<int>>& directions, int m, int n, int row, int col, int steps)
    {
        queue<Cell>q;
        q.push({row,col,0,steps});
        obstacles[0][0] = grid[0][0];
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size;i++)
            {
                Cell c = q.front();
                q.pop();
                if(c.row == m-1 && c.col == n-1)
                    return c.steps;
                if(grid[c.row][c.col] == 1)
                    c.used_lives++;
                if(c.used_lives>k)
                    continue;
                //cout<<c.steps<<" "<<c.used_lives<<endl;
                for(vector<int> dir: directions)
                {
                    int nrow = c.row+dir[0];
                    int ncol = c.col+dir[1];
                    // if(isPossible(nrow,ncol,m,n) && c.used_lives+grid[nrow][ncol]>k)
                    //     continue;
                    if(isPossible(nrow,ncol,m,n) && 
                       obstacles[nrow][ncol]>c.used_lives+grid[nrow][ncol])
                    {
                        //cout<<nrow<<" "<<ncol<<" "<<c.steps+1<<endl;
                        q.push({nrow,ncol,c.used_lives,c.steps+1});
                        obstacles[nrow][ncol] = c.used_lives+grid[nrow][ncol];
                    }
                }
             }
        }
        return -1;
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        //min obstacles to pass to reach i,j
        vector<vector<int>>obstacles(m,vector<int>(n,INT_MAX));
        vector<vector<int>>directions= {{-1,0},{1,0},{0,1},{0,-1}};
        return bfs(grid,k,obstacles,directions,m,n,0,0,0);
        
        // helper(grid,visited,k,m,n,0,0,0);
        // if(min_steps==INT_MAX)
        //     return -1;
        // return min_steps;
    }
};