class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        unordered_map<int,int>mp;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int count=0,sum;
        for(int startcol = 0; startcol<n; startcol++)
        {
            for(int endcol=startcol; endcol<n; endcol++)
            {
                mp.clear();
                //to not consider different case for sum, if (sum == target) will be consider in this
                mp[0] = 1;
                sum = 0;
                //same logic as subarray sum equals target
                for(int row = 0; row<m; row++)
                {
                    sum+= matrix[row][endcol] - (startcol>0 ? matrix[row][startcol-1] : 0);
                    count+= mp.find(sum-target)!=mp.end() ? mp[sum-target]:0;
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};