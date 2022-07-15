class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string t = countAndSay(n-1);
        string s = "";
        int size = t.size();
        int count = 1;
        for(int i=0; i<size-1; i++)
        {
            if(t[i] == t[i+1]) {
                count++;
                continue;
            }
            string temp = to_string(count) + t[i];
            s+=temp;
            count = 1;
        }
        string temp = to_string(count) + t[size-1];
        s+=temp;
        return s;
    }
};