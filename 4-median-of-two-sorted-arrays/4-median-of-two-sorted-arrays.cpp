class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n)
            return findMedianSortedArrays(nums2,nums1);
         int low = 0;
         int high = m;
        while(low<=high)
        {
            int cut1 = (low+high)/2;
            int cut2 = ((m+n+1)/2)-cut1;
            
            // According to both cuts, both array is divided into two parts
            // Left part: [0,cut1) of nums1 & [0,cut2) of nums2
            // Right part: [cut1,n1) of nums1 & [cut2,n2) of nums2
            // Find the end points of left part and start point of right part
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == m ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n ? INT_MAX : nums2[cut2];
            
            if(left1<=right2 && left2<=right1)
            {
                if((m+n)&1) //odd number of elements
                {
                    int x = max(left1,left2);
                    double median = (double)x;
                    return median;
                }
                else //even num of elements
                {
                    int x = max(left1,left2);
                    int y = min(right1,right2);
                    double median = (x+y)/2.0;
                    return median;
                }
            }
            else if(left1>right2)
                high = cut1-1;
            //left2 > right1
            else
                low = cut1+1;
        }
        return 0.0;
    }
};