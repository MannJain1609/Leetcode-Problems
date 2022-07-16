#define MOD 1000000007
class Solution {
private:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    bool isValid(int x, int y, int m, int n) {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    // bool isCorner(int x, int y, int m, int n) {
    //     if((x==0 && y==0) || (x==0 && y==n-1) || (x==m-1 && y==0) || (x==m-1 && y==n-1))
    //         return true;
    //     return false;
    // }
    int dfs(int m, int n, int k, int i, int j, vector<vector<vector<int>>>& dp) 
    {
        if(k<0)
            return 0;
        if(!isValid(i,j,m,n))
            return 1;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        long long u = dfs(m,n,k-1,i-1,j,dp);
        long long d = dfs(m,n,k-1,i+1,j,dp);
        long long l = dfs(m,n,k-1,i,j-1,dp);
        long long r = dfs(m,n,k-1,i,j+1,dp);
        long long x = (u+d+l+r)%MOD;
        return dp[i][j][k] = (int)x;
    }
//     int bfs(int m, int n, int maxMove, int startRow, int startColumn) {
//         //int MOD = 1e9+7;
//         //vector<vector<bool>>visited(m,vector<bool>(n,false));
//         queue<pair<int,int>>q;
//         q.push({startRow,startColumn});
//         // visited[startRow][startColumn] = true;
//         int dp[m][n][maxMove+1];
//         memset(dp,-1,sizeof(dp[0][0][0])*m*n*(maxMove+1));
//         int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
//         int move = 0,paths=0;
//         while(!q.empty())
//         {
//             int size = q.size();
//             for(int i=0; i<size; i++)
//             {
//                 pair<int,int> cell = q.front();
//                 q.pop();
//                 if(move>=maxMove)
//                     return paths;
//                 if(cell.first == 0 || cell.first==m-1 || cell.second == 0 || cell.second == n-1) {
//                     if(m==1 ||n==1)
//                         paths = (paths+1)%MOD;
//                     if(isCorner(cell.first,cell.second,m,n))
//                         paths = (paths+2)%MOD;
//                     else
//                         paths = (paths+1)%MOD;
                    
//                 }
//                 for(auto dir: directions) {
//                     int x = cell.first + dir[0];
//                     int y = cell.second + dir[1];
                    
//                     if(isValid(x,y,m,n))
//                         q.push({x,y});
//                 }
//             }
//             move++;
//         }
//         return paths;
//     }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return dfs(m,n,maxMove,startRow,startColumn,dp);
    }
};