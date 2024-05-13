class Solution {
public:
    double pow(double x, long long n)
    {
        if(n == 0)
            return 1;
        double ans = 1;
        while(n > 0)
        {
            if(n&1) {
                ans = ans*x;
                n--;
            }
            x = x*x;
            n = (n>>1);
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(x == 1)
            return x;
        if(x == -1)
        {
            if(n&1)
                return -1;
            else
                return 1;
        }
        //bool neg = false;
        long long t = n;
        if(t < 0)
        {
            t = -t;
            x = 1/x;
            //neg = true;
        }
        return pow(x,t);
    }
};