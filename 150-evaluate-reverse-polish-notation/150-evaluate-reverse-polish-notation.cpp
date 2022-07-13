class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        int size = tokens.size();
        for(int i=0; i<size; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                char opr = tokens[i][0];
                int x = stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                int ans;
                switch(opr) {
                    case '+' :
                        ans = x+y;
                        break;
                    case '-' :
                        ans = y-x;
                        break;
                    case '*' :
                        ans = y*x;
                        break;
                    case '/' :
                        ans = y/x;
                        break;
                    default:
                        ans = 0;
                        break;
                }
                s.push(to_string(ans));
            }
            else
                s.push(tokens[i]);
        }
        return stoi(s.top());
    }
};