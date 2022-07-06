class Solution {
private:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<bool>>& visited, 
             int m, int n, int row, int col, int prev)
    {
        if(row<0 || col<0 || row>=m || col>=n || visited[row][col] || matrix[row][col] <= prev)
            return 0;
        if(dp[row][col]!=-1)
            return dp[row][col];

        visited[row][col] = true;
        if(matrix[row][col] > prev)
        {
            for(auto dir : directions)
            {
                int dx = row + dir[0];
                int dy = col + dir[1];
                
                int s = 1+dfs(matrix,dp,visited,m,n,dx,dy,matrix[row][col]);
                dp[row][col] = max(dp[row][col],s);
             }
        }
        visited[row][col] = false;
        return dp[row][col];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int maxlen = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                maxlen = max(maxlen,dfs(matrix,dp,visited,m,n,i,j,-1));  
            }
        }
        return maxlen;
    }
};