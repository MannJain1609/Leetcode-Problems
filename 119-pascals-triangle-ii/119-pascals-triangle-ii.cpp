class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=2; i<=rowIndex+1; i++)
        {
            vector<int>temp(i);
            int size = ans[i-2].size();
            temp[0] = ans[i-2][0];
            temp[i-1] = ans[i-2][size-1];
            for(int j=1; j<i-1; j++) {
                //cout<<ans[i-2][j-1]<<" "<<ans[i-2][j]<<" : ";
                temp[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(temp);
            //cout<<"\n";
        }
        return ans[rowIndex];
    }
};