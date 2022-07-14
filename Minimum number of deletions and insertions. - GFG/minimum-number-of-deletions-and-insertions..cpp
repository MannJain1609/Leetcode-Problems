// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    
	    unordered_map<char,int>mp;
	   // for(int i=0; i<n; i++)
	   // {
	   //     mp[str2[i]]++;
	   // }
	    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
	    for(int i=0; i<=m; i++)
	    {
	        for(int j=0; j<=n; j++)
	        {
	            if(i==0)
	                dp[i][j] = j;
	           else if(j==0)
	                dp[i][j] = i;
	           //else if(mp[str1[i-1]]==0){
	           //    dp[i][j] = 1+dp[i-1][j];
	           //}
	           else {
	               if(str1[i-1] == str2[j-1])
	                    dp[i][j] = dp[i-1][j-1];
	                else
	                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
	           }
	        }
	    }
	    return dp[m][n];
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends