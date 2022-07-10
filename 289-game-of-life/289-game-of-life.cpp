class Solution {
private:
    bool isValid(int i, int j, int m, int n) {
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    int countNeighbours(vector<vector<int>>& board, int i, int j, int m, int n)
    {
        int neighbour = 0;
        int directions[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(auto dir: directions)
        {
            int dx = i + dir[0];
            int dy = j + dir[1];
            if(isValid(dx,dy,m,n) && board[dx][dy]==1)
                neighbour++;
            if(neighbour>3)
                return neighbour;
        }
        return neighbour;
    }
    void helper(vector<vector<int>>& board, vector<vector<int>>& grid, int m, int n) {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int num = countNeighbours(board,i,j,m,n);
                if(board[i][j] == 1 && num>=2 && num<4)
                    grid[i][j] = 1;
                if(board[i][j] == 0 && num == 3)
                    grid[i][j] = 1;
            }
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> grid(m,vector<int>(n,0));
        helper(board,grid,m,n);
        board = grid;
    }
};