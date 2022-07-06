class Solution {
private:
//     struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const
//     {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
 
//         if (hash1 != hash2) {
//             return hash1 ^ hash2;             
//         }
         
//         // If hash1 == hash2, their XOR is zero.
//           return hash1;
//     }
// };
    bool checkCycle(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
                    int m, int n, int row, int col, int parent_row, int parent_col) 
    {
        visited[row][col] = true;
        //cout<<row<<" "<<col<<" "<<parent_row<<" "<<parent_col<<endl;
        //up
        if(row-1>=0 && grid[row-1][col] == grid[row][col])
        {
            bool t = false;
            if(!visited[row-1][col])
            {
                t = checkCycle(grid,visited,m,n,row-1,col,row,col);
                if(t)
                    return true;
            }
            else if(!t && (parent_row!=row-1 || parent_col!=col))
                return true;
        }
        //cout<<row<<" "<<col<<" "<<"mgfvgf\n";
        //down
        if(row+1<m && grid[row+1][col] == grid[row][col])
        {
            bool t = false;
            if(!visited[row+1][col]) {
                t = checkCycle(grid,visited,m,n,row+1,col,row,col);
                if(t)
                    return true;
            }
            else if(!t && (parent_row!=row+1 || parent_col!=col))
                return true;
        }
        //cout<<row<<" "<<col<<" "<<"ctcht\n";
        //left 
        if(col-1>=0 && grid[row][col-1] == grid[row][col])
        {
            bool t = false;
            if(!visited[row][col-1]) {
                t = checkCycle(grid,visited,m,n,row,col-1,row,col);
                if(t)
                    return true;
            }
            else if(!t && (parent_row!=row || parent_col!=col-1))
                return true;
        }
        //cout<<row<<" "<<col<<" "<<"cdrer\n";
        //right
        if(col+1<n && grid[row][col+1] == grid[row][col])
        {
            bool t = false;
            if(!visited[row][col+1]) {
                t = checkCycle(grid,visited,m,n,row,col+1,row,col);
                if(t)
                    return true;
            }
            else if(!t && (parent_row!=row || parent_col!=col+1))
                return true;
        }
        //cout<<row<<" "<<col<<" "<<"fctdrty\n";
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //cout<<"message\n";
                if(!visited[i][j] && checkCycle(grid,visited,m,n,i,j,-1,-1))
                    return true;
            }
        }
        return false;
    }
};