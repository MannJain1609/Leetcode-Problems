class Solution {
private:
    void mergeSortandCount(vector<pair<int,int>>& v, vector<int>& counts, int left, int right)
    {
        if(left>=right)
            return;
        int mid = left + (right-left)/2;
        mergeSortandCount(v,counts,left,mid);
        mergeSortandCount(v,counts,mid+1,right);
        mergeandCount(v,counts,left,mid,right);
    }
    
    void mergeandCount(vector<pair<int,int>>& v, vector<int>& counts, int left, int mid, int right)
    {
        int leftpos = left,rightpos = mid+1;
        int numsElemRightLessThanLeft = 0;
        vector<pair<int,int>>merged;
        while(leftpos<=mid && rightpos<=right)
        {
            if(v[leftpos].first > v[rightpos].first)
            {
                numsElemRightLessThanLeft++;
                merged.push_back(v[rightpos]);
                rightpos++;
            }
            else
            {
                counts[v[leftpos].second]+=numsElemRightLessThanLeft;
                merged.push_back(v[leftpos]);
                leftpos++;
            }
        }
        while(leftpos<=mid)
        {
            counts[v[leftpos].second]+= numsElemRightLessThanLeft;
            merged.push_back(v[leftpos]);
            leftpos++;
        }
        while(rightpos<=right)
        {
            merged.push_back(v[rightpos]);
            rightpos++;
        }
        int pos = left;
        for(pair<int,int> m : merged)
        {
            v[pos] = m;
            pos++;
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> counts(size,0);
        vector<pair<int,int>>v;
        for(int i=0; i<size; i++)
        {
            v.push_back({nums[i],i});
        }
        mergeSortandCount(v,counts,0,size-1);
        return counts;
    }
};