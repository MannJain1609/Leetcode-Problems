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
    int dotCount = 0;
    void helper(vector<string>& ans, string s, string ip, int size, int index) {
       if(index>size || dotCount > 4)
           return;
        if(dotCount == 3 && ip.size() == size+3 && validIP4(ip))
            ans.push_back(ip);
        //cout<<index<<" "<<dotCount<<" "<<ip<<endl;
        string add(1,s[index]);
        dotCount++;
        helper(ans,s,ip+add+".",size,index+1);
        dotCount--;
        helper(ans,s,ip+add,size,index+1);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int size = s.size();
        if(size>12 || size<4)
            return ans;
        helper(ans,s,"",size,0);
        return ans;
    }
};