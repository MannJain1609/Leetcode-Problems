class Solution {
    int helper(string& text1, string& text2, int ind1, int ind2, int n, int m, vector<vector<int>>& memo) {
        if(ind1>=n || ind2>=m)
            return 0;
        if(memo[ind1][ind2] !=-1)
            return memo[ind1][ind2];
        if(text1[ind1] == text2[ind2])
            return memo[ind1][ind2] = 1 + helper(text1,text2,ind1+1,ind2+1,n,m,memo);
        return memo[ind1][ind2] = 
            max(helper(text1,text2,ind1,ind2+1,n,m,memo),helper(text1,text2,ind1+1,ind2,n,m,memo));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return helper(text1,text2,0,0,n,m,memo);
    }
   
    
//     int helper(string& str1, string& str2, int i1, int i2, int n1, int n2,vector<vector<int>>& dp)
//     {
//         // base case, if one of the string is empty
        
//         if(i1 == n1 || i2 == n2)
//             return 0;
        
//         // if already calculated
        
//         if(dp[i1][i2] != -1)
//             return dp[i1][i2];
        
//         // if characters are matching
        
//         if(str1[i1] == str2[i2])  
//             return dp[i1][i2] = 1 + helper(str1, str2, i1 + 1, i2 + 1, n1, n2,dp);
        
//         // if characters are not matching
        
//         else
//         {
//             return dp[i1][i2] = max(helper(str1, str2, i1 + 1, i2, n1, n2,dp), helper(str1, str2, i1, i2 + 1, n1, n2,dp));
//         }
//     }
    
//     int longestCommonSubsequence(string str1, string str2) {
        
//         int n1 = str1.size();
        
//         int n2 = str2.size();
		
// 		// initialize dp
        
//         vector<vector<int>>dp(n1,vector<int>(n2,-1));
        
//         return helper(str1, str2, 0, 0, n1, n2,dp);
//     }
};