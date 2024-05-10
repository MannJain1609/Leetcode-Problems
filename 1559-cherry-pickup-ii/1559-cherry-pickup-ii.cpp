class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if(i <0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    //int helper(int i, int j1, int j2, int m, int n, vector<vector<vector<int>>>& dp)
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int i=m-1; i>=0; i--)
        {
            for(int j1 = 0; j1<n; j1++)
            {
                for(int j2=0; j2<n; j2++)
                {
                    int num = 0;
                    if(j1 == j2)
                        num = grid[i][j1];
                    else
                        num = grid[i][j1] + grid[i][j2];
                    dp[i][j1][j2] = num;
                    for(int t=(-1); t<=1; t++)
                    {
                        if(!isValid(i+1,j1+t,m,n))
                            continue;
                        for(int k=-1; k<=1; k++)
                        {
                            if(isValid(i+1,j2+k, m,n))
                                dp[i][j1][j2] = max(dp[i][j1][j2], num + dp[i+1][j1+t][j2+k]);
                        }
                    }
                }
            }
        }
        return dp[0][0][n-1];

        // vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        // vector<vector<int>>dir = {{1,-1},{1,0},{1,1}};
        // for(int i = m-1; i>=0; i--)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         int row = -1, col = -1;
        //         for(vector<int>& d : dir)
        //         {
        //             int new_i = d[0] + i;
        //             int new_j = d[1] + j;
        //             if(isValid(new_i, new_j, m ,n))
        //             {
        //                 if(dp[i][j][0] > grid[i][j] + dp[new_i][new_j][0]) {
        //                     dp[i][j][0] = grid[i][j] + dp[new_i][new_j][0];
        //                     row = i;
        //                     col = j;
        //                 }
        //             }
        //             else {
        //                 if(dp[i][j][0] > grid[i][j])
        //                 {
        //                     dp[i][j][0] = grid[i][j];
        //                     row = i;
        //                     col = j;
        //                 }
        //             }
        //         }
        //         grid[row][col] = 0;
        //         for(vector<int>& d : dir)
        //         {
        //            int new_i = d[0] + i;
        //             int new_j = d[1] + j;

        //             if(isValid(new_i, new_j, m ,n) )
        //             {
        //                 if(dp[i][j][1] > grid[i][j] + dp[new_i][new_j][1]) {
        //                     dp[i][j][1] = grid[i][j] + dp[new_i][new_j][1];
        //                     row = i;
        //                     col = j;
        //                 }
        //             } 
        //             else {
        //                 if(dp[i][j][1] > grid[i][j])
        //                 {
        //                     dp[i][j][1] = grid[i][j];
        //                 }
        //             }
        //         }
        //     }
        // }
        // return max(dp[0][0][0] + dp[0][n-1][1], dp[0][0][1]+dp[0][n-1][0]);
    }
};