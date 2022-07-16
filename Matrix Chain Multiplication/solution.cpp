//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(int N, int arr[], int start, int end,vector<vector<int>>& dp)
    {
        if(start>=end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int min_ops = INT_MAX;
        for(int k=start; k<end; k++)
        {
            int a = solve(N,arr,start,k,dp);
            int b = solve(N,arr,k+1,end,dp);
            int temp = a + b + arr[start-1]*arr[k]*arr[end];
            min_ops = min(min_ops,temp);
        }
        return dp[start][end] = min_ops;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return solve(N,arr,1,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
