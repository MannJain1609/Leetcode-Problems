// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  private:
    void SubsetSum(int arr[], int sum, int n, vector<vector<bool>>& dp)
    {
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(j==0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = false;
                else
                {
                    if(j-arr[i-1]>=0)
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++)
	    {
	        sum+=arr[i];
	    }
	    int x = sum/2;
	    int min_diff = sum;
	    vector<vector<bool>>dp(n+1,vector<bool>(x+1,false));
	    SubsetSum(arr,x,n,dp);
	    for(int i=0; i<=x; i++)
	    {
	        //cout<<i<<" "<<isSubsetSum(arr,i,n)<<"\n";
	        if(dp[n][i]) {
	            //cout<<i<<" ";
	            min_diff = min(min_diff,sum-2*i);
	        }
	    }
	    return min_diff;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends