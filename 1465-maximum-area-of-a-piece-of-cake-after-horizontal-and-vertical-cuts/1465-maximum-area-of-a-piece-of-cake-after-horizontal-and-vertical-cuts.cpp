#define MOD 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int hsize = horizontalCuts.size();
        int vsize = verticalCuts.size();
        int max_height = horizontalCuts[0],max_width = verticalCuts[0];
        for(int i=0; i<hsize; i++)
        {
            if(i == hsize-1)
                max_height = max(max_height,h - horizontalCuts[i]);
            else
                max_height = max(max_height,horizontalCuts[i+1] - horizontalCuts[i]);
        }
        for(int i=0; i<vsize; i++)
        {
            if(i ==vsize-1)
                max_width = max(max_width, w-verticalCuts[i]);
            else
                max_width = max(max_width,verticalCuts[i+1] - verticalCuts[i]);
        }
        int area = ((long long)max_height * max_width) % MOD;
        return area;
    }
};