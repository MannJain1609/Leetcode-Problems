// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int days = prices.size();
//         if (days==0) 
//             return 0;
        
//         vector<vector<int>> dp(k+1,vector<int>(days,0));
//         // Dp array with k+1 rows and days columns
//         // dp[i][j] represents maximum profit of i transactions upto j days
        
//         // dp[0][j] will be 0 as profit of 0 transactions is 0
//         // dp[i][0] will be 0 as profit upto first day is 0
        
//         for (int i=1;i<=k;i++) {
//             int temp = -prices[0];
                
//             for (int j=1;j<days;j++) {
//                 // dp[i][day] will be maximum of dp[i][day-1] and
//                 // dp[i-1][j]+new tx i.e max profit upto transaction i-1 and j<day
                
//                 int Max = dp[i][j-1];
//                 //bought on j-1th day and sold today
//                 temp = max(dp[i-1][j-1]-prices[j-1],temp);
//                 Max = max(Max,temp+prices[j]);
                
//                 dp[i][j] = Max;
//             }
//         }
        
//         return dp[k][days-1];
//     }
// };


//SOlution 2
class Solution {
public:
	vector<vector<int>> dp;
	int solve(vector<int> &prices,int n,int buy,int pos,int k){
		if(pos==n || buy==2*k) return 0;  // buy=2*k means k transactions(buy and sell) completed

		if(dp[pos][buy]!=-1) return dp[pos][buy];

		int ans=0;
		if(buy%2==0){
			ans=max(-prices[pos]+solve(prices,n,buy+1,pos+1,k),solve(prices,n,buy,pos+1,k));
		}
		else{
			ans=max(prices[pos]+solve(prices,n,buy+1,pos+1,k),solve(prices,n,buy,pos+1,k));
		}
		
		return dp[pos][buy] = ans;
	}
	int maxProfit(int k, vector<int>& prices) {
	
		int n=prices.size();
		dp.assign(n,vector<int>(2*k,-1));
		return solve(prices,n,0,0,k);
	}
};
