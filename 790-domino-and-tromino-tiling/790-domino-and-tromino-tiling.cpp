class Solution {
public:
    int numTilings(int n) {
        if(n<=2)
            return n;
        vector<int>f(n+1,0);
        vector<int>p(n+1,0);
        p[1] = 0;
        p[2] = 1;
        f[1] = 1;
        f[2] = 2;
        int MOD = 1000000007;
        for(int i=3; i<=n; i++)
        {
            p[i] = (f[i-2]%MOD + p[i-1]%MOD)%MOD;
            f[i] = (f[i-1]%MOD + f[i-2]%MOD + (2 * (long long)p[i-1])%MOD)%MOD;
        }
        return f[n];
    }
};