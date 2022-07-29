class Solution {
private:
    int helper(int dividend,int divisor) {
        if(divisor == dividend)
            return 1;
        bool isPositive = divisor<0 == dividend<0;
        unsigned int a  = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a>=b)
        {
            int q = 0;
            while(a > (b<<(q+1))) {
                q++;
            }
            ans+= (1<<q);
            a = a - (b<<q);
        }
        if(isPositive && ans == 1<<31)
            return INT_MAX;
        return isPositive ? ans : -ans;
    }
public:
    int divide(int dividend, int divisor) {
       return helper(dividend,divisor);
    }
};