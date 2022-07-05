class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_count = 0, high_count = 0,l=low,h=high;
        while(l)
        {
            low_count++;
            l = l/10;
        }
        while(h)
        {
            high_count++;
            h = h/10;
        }
        vector<int> ans;
        for(int len = low_count; len<=high_count; len++)
        {
            for(int i=1; i<=9; i++)
            {
                int num = 0;
                int prev = i,flag=1;
                for(int j=0; j<len; j++)
                {
                    num = num*10 + prev;
                    prev++;
                    if(prev>9 && j!=len-1) {
                        flag=0;
                        break;
                    }
                }
                if(flag && num>=low && num<=high)
                    ans.push_back(num);
                else if(num>high)
                    break;
            }
        }
        return ans;
    }
};