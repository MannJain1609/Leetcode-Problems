class Solution {
public:
//     int ans = INT_MIN;
//     int helper(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& dp)
//     {
//         if(dp[i][j] != INT_MIN)
//             return dp[i][j];
//         bool move = false;
//         int score = INT_MIN;
//         for(int r = i+1; r<m; r++)
//         {
//             move = true;
//             score = max(score, grid[r][j] - grid[i][j]);
//             int t= helper(grid,m,n,r,j,dp);
//             if(t != INT_MIN)
//                 score = max(score, grid[r][j] - grid[i][j] + t);
//         }
        
//         for(int c = j+1; c<n; c++)
//         {
//             move = true;
//             score = max(score, grid[i][c] - grid[i][j]);
//             int t = helper(grid,m,n,i,c,dp);
//             if(t != INT_MIN)
//                 score = max(score, grid[i][c] - grid[i][j] + t);
//         }
        
//         if(!move)
//             return INT_MIN;
//         ans = max(ans,score);
//         return dp[i][j] = score;
//     }
    
    
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,100001));
        dp[0][0] = grid[0][0];
        int maxScore = INT_MIN;
        for(int i=1; i<m; i++) { 
            dp[i][0] = min(grid[i-1][0], dp[i-1][0]);
            maxScore = max(maxScore, grid[i][0]-dp[i][0]);
        }

        for(int j=1; j<n; j++) {
            dp[0][j] = min(grid[0][j-1], dp[0][j-1]);
            maxScore = max(maxScore, grid[0][j] - dp[0][j]);
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                dp[i][j] = min(grid[i-1][j], grid[i][j-1]);
                dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1]));
                maxScore = max(maxScore, grid[i][j] - dp[i][j]);
            }
        }

        return maxScore;

        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,INT_MIN));
        // int ans = INT_MIN;
        // for(int i=m-1; i>=0; i--)
        // {
        //     for(int j=n-1; j>=0; j--)
        //     {
        //         if(i == m-1 && j == n-1)
        //             continue;
        //         bool move = false;
        //         int score = INT_MIN;
        //         for(int r = i+1; r < m; r++)
        //         {
        //             move = true;
        //             score = max(score, grid[r][j] - grid[i][j]);
        //             if(dp[r][j] != INT_MIN)
        //                 score = max(score, grid[r][j] - grid[i][j] + dp[r][j]);
        //         }
        //         for(int c = j+1; c < n; c++)
        //         {
        //             move = true;
        //             score = max(score, grid[i][c] - grid[i][j]);
        //             if(dp[i][c] != INT_MIN)
        //                 score = max(score,  grid[i][c] - grid[i][j] + dp[i][c]);
        //         }
        //         if(!move) {
        //             dp[i][j] = INT_MIN;
        //             continue;
        //         }
        //         dp[i][j] = score;
        //         ans = max(ans,dp[i][j]);
        //     }
        // }
        // return ans;
        
        // helper(grid,m,n,0,0,dp);
        // return ans;
        
    }
};