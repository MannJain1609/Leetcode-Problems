class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if(len == 1)
            return "";
        int s = -1;
        if(len %2 != 0)
            s = len/2;
        for(int i=0; i<len; i++)
        {
            if(i == s)
                continue;
            if(palindrome[i]!='a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        for(int i=len-1; i>=0; i--)
        {
            if(i == s)
                continue;
            if(palindrome[i]!= 'z')
            {
                palindrome[i]++;
                return palindrome;
            }
        }
        return "";
    }
};