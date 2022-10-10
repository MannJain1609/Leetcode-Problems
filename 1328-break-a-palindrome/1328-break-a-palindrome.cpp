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
        palindrome[len-1] = 'b';
        return palindrome;
    }
};