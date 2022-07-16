//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    //eval represents what we need the expression to
    int solve(int n, string s, int start, int end, bool eval, vector<vector<vector<int>>>& dp)
    {
        if(start>end)
            return 0;
            
        if(dp[start][end][eval?1:0]!=-1)
            return dp[start][end][eval?1:0];
            
        if (start==end) {
            if (eval) // Evaluate expression to true
                return s[start]=='T' ? 1:0;
            else // Evaluate expression to false
                return s[start]=='F' ? 1:0;
        }
        
        long long count = 0;
        for(int k=start+1; k<=end-1; k+=2)
        {
            int leftTrue = solve(n,s,start,k-1,true,dp);
            int leftFalse = solve(n,s,start,k-1,false,dp);
            int rightTrue = solve(n,s,k+1,end,true,dp);
            int rightFalse = solve(n,s,k+1,end,false,dp);
            
            char opr = s[k];
           
            if(opr == '&')
            {
                if(eval)
                    count = count + leftTrue*rightTrue;
                else
                    count = count + leftTrue*rightFalse +
                            leftFalse*rightTrue + leftFalse*rightFalse;
            }
            else if(opr == '|')
            {
                if(eval)
                    count = count + leftTrue*rightFalse +
                            leftFalse*rightTrue + leftTrue*rightTrue;
                else
                    count = count + leftFalse*rightFalse;
            }
            else
            {
                if(eval)
                    count = count + leftFalse*rightTrue + leftTrue*rightFalse;
                else
                    count = count + leftTrue*rightTrue + leftFalse*rightFalse;
            }
        }
        return dp[start][end][eval?1:0] = (int)count%1003;
    }
public:
    int countWays(int N, string S){
        // code here
        int size = S.size();
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return solve(N,S,0,size-1,true,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
