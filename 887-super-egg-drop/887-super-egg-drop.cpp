class Solution {
private:
    int solve(int n, int k, vector<vector<int>>& dp) {
        if(k==1)
            //try on every floor, starting from first
            //worst case n
            return n;
        //only one floor, one move is req
        if(n==0 || n==1)
            return n;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int min_move = INT_MAX;
        int low=1,high=n;
        while(low<=high)
        {
            int i = low + (high-low)/2;
            //dropping egg from ith floor
            //if break, try the lower floors with one egg less
            int Break = solve(i-1,k-1,dp);
            //if not break, try upper floors
            //egg can be reused
            //n-i floors remains
            int NotBreak = solve(n-i,k,dp);
            //moves will be equal to the worst case for certainty
            int currMoves = 1 + max(Break,NotBreak);
            //if chosen ith floor gives minimum or not
            min_move = min(min_move,currMoves);
            
            if(Break > NotBreak)
                // Left part require more moves than right
                // As we need more currMoves value
                // Going to the worst case part 
                high = i-1;
            else
                low = i+1;
        }
        return dp[n][k] = min_move;
    }
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};