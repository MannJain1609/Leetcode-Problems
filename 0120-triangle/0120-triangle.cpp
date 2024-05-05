class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        int size2 = triangle[size-1].size();
        int minSum = INT_MAX;
        vector<vector<int>>dp(size,vector<int>(size2,INT_MAX));
        for(int i=0; i<size2; i++)
            dp[size-1][i] = triangle[size-1][i];
        for(int i=size-2; i>=0; i--) {
            size2--;
            int n = size2;
            for(int j=0; j<n; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};