// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

// To make 1 pair of socks

// Take one from each N different color socks 
// Now the next (n+1)th sock will guarantee a pair 
   

// To make k pair of socks

   

// Divide socks into two groups 
// Group 1 should contain at least one sock of each color 
// Hence group 1 contains 1 sock for odd no of socks available and 2 socks for even no of socks available 
// Group 2 contains the remaining socks which doesn't belong to group 1
// Group 2 contains even no of socks of each color (including 0)
// Suppose no of pairs group 2 can form is g2Pairs
// There are two cases now: g2Pairs>=k & g2Pairs<k
   

// If g2Pairs>=k i.e no of pairs group 2 can create is more than or eqaul to k
// Choose 2*(k-1) socks from group 2 
// Now choose N socks from group 1 (Each color sock once)
// Now these 2*(k-1)+N socks guarantee that there are (k-1) pairs of socks.
// This is because when we choose 2*(k-1) socks from group 2 if even no of socks of particular color is chosen, it makes a pair and if odd no of socks of a color is chosen the N socks of all color from group 2 will make pair complete. Hence in the worst case we will have k-1 pairs available with us
// Now Choose 1 more to complete the Kth pair 
   

 

// If g2Pairs<k
// The group 2 does not have enough socks to form k pairs
// Take all socks from g2Pairs 
// Now choose N socks from group 1 (Each color sock once)
// Now these 2*(g2Pairs)+N socks guarantee that there are g2Pairs pairs of socks
// Now Choose (k-g2Pairs) more to complete all the K pairs
	public:
	int find_min(int a[], int n, int k) {
        // Your code geos here
    int pairs=0;
    for(int i=0;i<n;i++)
      pairs +=a[i]/2;
      
      
    if(k>pairs)
      return -1;
    
    //g2 pairs  
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(a[i]-1)/2;
    }
    
    if(k>sum)
        return 2*sum+n+(k-sum);
    
    else
        return 2*(k-1)+n+1;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}
  // } Driver Code Ends