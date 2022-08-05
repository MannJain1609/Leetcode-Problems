class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // if(left == 0 || right == 0)
        //     return 0;
        // if(left==INT_MAX)
        //     return INT_MAX;
        // if(right == INT_MAX)
        //     right = right-1;
        // int x = int(log2(left));
        // x = x + 1;
        // int p = right;
        // if(x!=31)
        //     p = pow(2,x);
        // if(right>p)
        //     return 0;
        // int res = left;
        // for(int i=left+1; i<=right; i++)
        //     res = res & i;
        // return res;
        int count = 0;
        // int x = (int)log2(left);
        // if((x&(x-1)) != 0)
        //     x = x+1;
        while(left!=right)
        {
            left = left>>1;
            right = right>>1;
            count++;
        }
        return left<<count;
    }
};