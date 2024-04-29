class Solution {
public:
    bool isValidIP(string queryIP) {
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

    void helper(vector<string>& ans, string s, string IP, int i, int n, int dots) {
        if(i==n) {
            if(dots == 3 && IP.size() == n + 3 && isValidIP(IP)) 
                ans.push_back(IP);
            return;
        }
        if(dots < 3) {
            helper(ans,s,IP+'.'+s[i], i+1,n, dots+1);
        }
        helper(ans,s,IP+s[i],i+1, n, dots);
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        int n = s.size();
        helper(ans,s,"",0,n,0);
        return ans;
    }
};