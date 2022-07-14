// { Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}// } Driver Code Ends


int maxSubsequenceSubstring(string text1, string text2, int n, int m){
    //code
    int maxlen = 0;
 vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j];
            maxlen = max(dp[i][j],maxlen);
        }
    }
    return maxlen;
    
}