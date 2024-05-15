class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        int maxSoFar = 0;
        for(int i=0; i<n; i++)
        {
            if(height[i] > maxSoFar)
                maxSoFar = height[i];
            left[i] = maxSoFar;
        }
        maxSoFar = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(height[i] > maxSoFar)
                maxSoFar = height[i];
            right[i] = maxSoFar;
        }

        int trap =0;
        for(int i=0; i<n; i++)
        {
            trap += min(left[i],right[i]) - height[i];
        }
        return trap;
    }
};