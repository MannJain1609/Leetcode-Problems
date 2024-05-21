#define ll long long
class Solution {
public:
    ll dp[50][50][2];
    ll helper(int pos, int k, int jump, int back, int stat, vector<ll>& exp)
    {
        if(pos > k+1)
            return 0;
        if(dp[jump][back][stat] != -1)
            return dp[jump][back][stat];

        ll ans = 0;
        if(pos == k)
            ans++;
        ans += helper(pos+exp[jump], k ,jump+1,back,1,exp);
        if(stat == 1)
            ans += helper(pos-1,k,jump,back+1, 0,exp);
        return dp[jump][back][stat] = ans;
    }
    int waysToReachStair(int k) {
        memset(dp,-1,sizeof(dp));
        vector<ll> exp(33);
        exp[0] = 1;

        for(int i=1; i<33; i++)
            exp[i] = (ll)2 * exp[i-1];
        ll ans = helper(1,k,0,0,1,exp);
        return (int)ans;
    }
};