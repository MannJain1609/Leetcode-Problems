class Solution {
public:
    int calculate(string s) {
        stack<int>nums;
        long num = 0;
        char op = '+';
        int size = s.size();
        int i=0;
        int sign = 1,res = 0; //+ve
        while(i<size) {
            if(isdigit(s[i]))
                num = num*10 + s[i] - '0';
            else if(s[i] == '+') {
                res += (int)num*sign;
                num = 0;
                sign = 1;
            }
            else if(s[i] == '-') {
                res+= (int)num*sign;
                num = 0;
                sign = -1;
            }
            else if(s[i] == '(') {
                nums.push(res);
                nums.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                res+=(int)num*sign;
                num = 0;
                int Sign = nums.top();
                nums.pop();
                int Val = nums.top();
                nums.pop();
                res = res*Sign + Val;
            }
            i++;
        }
        res+=(int)num*sign;
        return res;
    }
};