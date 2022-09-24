class Solution {
// private:
//     int numberofBits(int n)
//     {
//         return log2(n)+1;
//     }
public:
    int concatenatedBinary(int n) {
        int MOD = 1000000007;
        long long ans = 0;
        int len = 1;
        for(int i=1; i<=n; i++)
        {
            //int len = numberofBits(i);
            if(i>1 && (i & (i-1))==0)
                len++;
            ans = ((ans<<len)%MOD + i)%MOD;
        }
        return ans%MOD;
    }
};