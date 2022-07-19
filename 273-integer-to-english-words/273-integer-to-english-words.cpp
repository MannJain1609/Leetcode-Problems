class Solution {
public:
    string ones[11] =         
                        {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
    string tensBef20[11] = 
                        {"#","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",                                  "Seventeen", "Eighteen", "Nineteen"};
    string tensAft20[11] = {"#", "#", "Twenty", "Thirty", "Forty", "Fifty", "Sixty","Seventy",                                            "Eighty", "Ninety"};
    string numberToWords(int num) {
       string ans = ""; 
       if(num>=1e9)
       {
           ans+= numberToWords(num/1e9) + " Billion";
           if(num%1000000000>0)
                ans+= " " + numberToWords(num%1000000000);
       }
       else if(num>=1e6)
       {
           ans+= numberToWords(num/1e6) + " Million";
           if(num%1000000>0)
                ans+= " " + numberToWords(num%1000000);
       }
        else if(num>=1000)
        {
            ans+= numberToWords(num/1000) + " Thousand";
            if(num%1000>0)
                ans+= " " + numberToWords(num%1000);
        }
        else if(num>=100)
        {
            ans+= numberToWords(num/100) + " Hundred";
            if(num%100>0)
                ans+= " " + numberToWords(num%100);
        }
        else if(num>=20)
        {
            int i = num/10;
            ans+= tensAft20[i];
            if(num%10>0)
                ans+= " " + numberToWords(num%10);
        }
        else if(num>10)
        {
            int i = num - 10;
            ans+= tensBef20[i];
        }
        else 
        {
            ans+= ones[num];
        }
        return ans;
    }
};