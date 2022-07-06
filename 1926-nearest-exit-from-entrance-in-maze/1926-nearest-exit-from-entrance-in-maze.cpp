class Solution {
private:
    int bfs(vector<vector<char>>& maze, vector<int>& entrance, int m, int n) {
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        q.push({entrance[0],entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int steps = 0,flag = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                pair<int,int> cell = q.front();
                q.pop();
                int row = cell.first;
                int col = cell.second;
                //flag is for the case if entrance is the exit
                if(flag && (row == 0 || row == m-1 || col ==0 || col == n-1)) 
                    return steps;
                //up
                if(row-1>=0 && !visited[row-1][col] && maze[row-1][col] == '.') {
                    visited[row-1][col] = true;
                    q.push({row-1,col});
                }
                //down
                if(row+1<m && !visited[row+1][col] && maze[row+1][col] == '.') {
                    visited[row+1][col] = true;
                    q.push({row+1,col});
                }
                //left
                if(col-1>=0 && !visited[row][col-1] && maze[row][col-1] == '.') {
                    visited[row][col-1] = true;
                    q.push({row,col-1});
                }
                //right
                if(col+1<n && !visited[row][col+1] && maze[row][col+1] == '.') {
                    visited[row][col+1] = true;
                    q.push({row,col+1});
                }
            }
            flag = 1;
            steps++;
        }
        return -1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        return bfs(maze,entrance,m,n);
    }
};