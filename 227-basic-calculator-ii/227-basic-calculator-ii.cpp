class Solution {
private:
    bool isOperator(char c) {
        if(c=='+' || c=='-' || c=='*' || c=='/')
            return true;
        return false;
    }
public:
    int calculate(string s) {
        stack<int>nums;
        char opr='+';
        int size = s.size();
        int num = 0;
        for(int i=0; i<size; i++)
        {
            if(isdigit(s[i])) {
                long long x = (long long)num*10+s[i]-'0';
                num = (int)x;
            }
            if(!isdigit(s[i]) && !isspace(s[i]) || i==size-1) {
                if(opr == '+')
                    nums.push(num);
                else if(opr == '-')
                    nums.push(-num);
                else if(opr == '*') {
                    int res = nums.top() * num;
                    nums.pop();
                    nums.push(res);
                }
                else if(opr == '/') {
                    int res = nums.top()/num;
                    nums.pop();
                    nums.push(res);
                }
                opr = s[i];
                num = 0;
            }
        }
        int ans = 0;
        while(!nums.empty()) {
            ans+= nums.top();
            nums.pop();
        }
        return ans;
    }
};