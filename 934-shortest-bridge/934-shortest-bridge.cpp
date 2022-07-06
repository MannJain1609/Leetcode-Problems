class Solution {
private:
    queue<pair<int,int>>q;
    bool isValid(int x, int y, int m, int n)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    void dfs(vector<vector<int>>& grid,int m, int n, int i, int j)
    {
        if(!isValid(i,j,m,n) || grid[i][j] == 0 || grid[i][j] == 2)
            return;
        grid[i][j] = 2;
        q.push({i,j});
        dfs(grid,m,n,i-1,j);
        dfs(grid,m,n,i+1,j);
        dfs(grid,m,n,i,j-1);
        dfs(grid,m,n,i,j+1);
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool flag = false;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    //apply dfs and mark the whole island visited and push this island in q
                    dfs(grid,m,n,i,j);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        //Now we apply bfs and find the minimum distance
        int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int d = 0;
        while(!q.empty())
        {
            int size = q.size();
            flag = false;
            for(int i=0; i<size; i++)
            {
                pair<int,int> cell = q.front();
                q.pop();
                int row = cell.first;
                int col = cell.second;
                for(auto dir:directions)
                {
                    int dx = row + dir[0];
                    int dy = col + dir[1];
                    
                    if(!isValid(dx,dy,m,n))
                        continue;
                    //found the second island
                    if(grid[dx][dy] == 1)
                        return d;
                    
                    if(grid[dx][dy] == 0)
                    {
                        flag = true;
                        grid[dx][dy] = 2; //marked as visited
                        q.push({dx,dy});
                    }
                }
            }
            if(flag)
                d++;
        }
        return d;
    }
};