class Solution {
private:
    void solve(vector<int>& ans, int n, int k, int num, int min_nth)
    {
        if(n==0)
        {
            if(num >= min_nth)
                ans.push_back(num);
            return;
        }
        for(int j=0; j<=9; j++)
        {
            int x = num*10 + j;
            int last_digit = num%10;
            if(num == 0 || abs(j-last_digit)==k)
                solve(ans,n-1,k,x,min_nth);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        int min_nth = pow(10,n-1);
        solve(ans,n,k,0,min_nth);
        return ans;
    }
};