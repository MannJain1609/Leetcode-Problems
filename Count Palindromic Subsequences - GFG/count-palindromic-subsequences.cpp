// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int MOD = 1e9+7;
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.size();
       vector<vector<long long>>dp(n,vector<long long>(n,0));
       for(int i=n-1; i>=0; i--)
       {
           for(int j=i; j<n; j++)
           {
               if(i == j)
                    dp[i][j] = 1;
                else if(str[i]== str[j])
                    dp[i][j] = (1 + dp[i][j-1] + dp[i+1][j])%MOD;
                else 
                    dp[i][j] = (dp[i][j-1] - dp[i+1][j-1] + dp[i+1][j]+MOD)%MOD;
           }
       }
       return dp[0][n-1];
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends