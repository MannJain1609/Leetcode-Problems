// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) {
        // code here
        int x = N/M;
        int diff1,diff2,diff3,a,b,c;
        if(M == 1 || M==-1)
            return N;
            
        a = x*M;
        b = (x-1)*M;
        c = (x+1)*M;
        diff1 = abs(N-a);
        diff2 = abs(N-b);
        diff3 = abs(N-c);
    
        
        if(diff1 > diff2)
        {
            if(diff3 < diff2)
                return c;
            if(diff3 == diff2)
            {
                if(abs(b) > abs(c))
                    return b;
                else
                    return c;
            }
            else
                return b;
        }
        else if(diff1 == diff2)
        {
            if(diff3 < diff2)
                return c;
            if(diff3 == diff2)
            {
                int m = max(abs(a), max(abs(b), abs(c)));
                if(m == abs(a))
                    return a;
                else if(m == abs(b))
                    return b;
                else
                    return c;
            }
            else
            {
                if(abs(a)>abs(b))
                    return a;
                else
                    return b;
            }
        }
        else
        {
            if(diff3 < diff1)
                return c;
            if(diff3 == diff1)
            {
                if(abs(a) > abs(c))
                    return a;
                else
                    return c;
            }
            else
                return a;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends