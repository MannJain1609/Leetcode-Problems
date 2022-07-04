class Solution {
private:
    bool validIP4(string queryIP) {
        int size = queryIP.size();
        int i = 0;
        string num = "";
        int count = 0;
        while(i<size)
        {
            if(queryIP[i] == '.')
            {
                if(num=="" || num.size()>3 || stoi(num)>255 || (num.size()>1 && num[0]=='0'))
                    return false;
                count++;
                num = "";
            }
            else if(!isdigit(queryIP[i]))
                return false;
            else
                num+=queryIP[i];
            i++;
        }
        if(num.size()>1 && num[0]=='0')
            return false;
        if(count == 3 && num!="" && num.size()<=3 && stoi(num)<=255)
            return true;
        return false;
    }
    bool check(string s) {
        if(s.size() <1 || s.size() > 4)
            return false;
        int size = s.size();
        for(int i=0; i<size; i++)
        {
            if(isdigit(s[i]) || (s[i]>='a' && s[i]<='f') || (s[i]>='A' && s[i]<='F')) 
                continue;
            else
                return false;
        }
        return true;
    }
    bool validIP6(string queryIP) {
        int size = queryIP.size();
        int i=0; 
        string num ="";
        int count = 0;
        while(i<size)
        {
            if(queryIP[i] == ':')
            {
                if(!check(num))
                    return false;
                count++;
                num = "";
            }
            else
                num+=queryIP[i];
            i++;
        }
        if(count == 7 && check(num))
            return true;
        return false;
    }
public:
    string validIPAddress(string queryIP) {
        if(validIP4(queryIP))
            return "IPv4";
        else if(validIP6(queryIP))
            return "IPv6";
        return "Neither";
    }
};