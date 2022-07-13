class Solution {
public:
    bool isNumber(string s) {
        int size = s.size();
        int dot_count = 0,eCount = 0;
        bool flag = false, isSign = false,hasdigit = false;
        for(int i=0; i<size; i++)
        {
            if(isdigit(s[i])) {
                hasdigit = true;
                isSign = false;
                continue;
            }
            if(s[i] == '.') {
                if(flag || i==size-1 && !hasdigit)
                    return false;
                dot_count++;
                if(dot_count>1)
                    return false;
            }
            else if(s[i] == '+' || s[i] == '-') {
                if(isSign || size==1)
                    return false;
                if(!flag && i!=0)
                    return false;
                if(flag && s[i-1]!='e' && s[i-1] != 'E')
                    return false;
                isSign = true;
            }
            else if(s[i] == 'e' || s[i] == 'E') {
                if(!hasdigit)
                    return false;
                eCount++;
                if(eCount>1)
                    return false;
                flag = true;
                
            }
            else
                return false;
        }
        if(s[size-1]=='e' || s[size-1]=='E' || s[size-1]=='+' || s[size-1] == '-')
            return false;
        return true;
    }
};