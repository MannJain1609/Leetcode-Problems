//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int helper(vector<int>& nums, int k, int index, int rem, vector<vector<int>>& dp)
    {
        if(index==nums.size())
            return 0;
        if(dp[index][rem]!=-1)
            return dp[index][rem];
        //word cannot fit in this line
        //add in new line
        int cost = INT_MAX;
        if(nums[index]>rem) {
            //new line has a space of k chars
            int h1 = helper(nums,k,index+1,k-nums[index]-1,dp);
            cost = (rem+1)*(rem+1) + h1;
        }
        else if(nums[index] == rem) {
            //word can be added in same line as well as new line
            
            //Adding in same line, so there will be no rem space
            //new word will be added in new line, k space will be available
            int h1 = helper(nums,k, index+1,k,dp);
            //adding in new line
            int h2 = helper(nums,k,index+1,k-nums[index]-1,dp);
            cost = min(h1,(rem+1)*(rem+1)+h2);
        }
        //nums[index]<rem
        else {
            //word can be added in same line for new line
            //added in same line
            int h1 = helper(nums,k,index+1,rem-nums[index]-1,dp);
            //added in new line
            int h2 = helper(nums,k,index+1,k-nums[index]-1,dp);
            cost = min(h1,(rem+1)*(rem+1)+h2);
        }
        return dp[index][rem] = cost;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(nums,k,0,k,dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
