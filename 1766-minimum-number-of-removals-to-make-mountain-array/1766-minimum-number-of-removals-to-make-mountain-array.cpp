class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        //LIS containing one element
        vector<int>temp;
        for(int i=0; i<n; i++)
        {
            if(temp.size()==0 || temp.back() < nums[i]) {
                temp.push_back(nums[i]);
                left[i] = temp.size();
            }
            else {
                int pos = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[pos] = nums[i];
                left[i] = pos+1;
            }
        }

        temp.clear();
        for(int i=n-1; i>=0; i--)
        {
            if(temp.size() == 0 || temp.back() < nums[i]) {
                temp.push_back(nums[i]);
                right[i] = temp.size();
            }
            else {
                int pos = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[pos] = nums[i];
                right[i] = pos+1;
            }
        }

        int maxlen = 0;
        for(int i=1; i<n-1; i++)
        {
            if(left[i] == 1 || right[i]==1)
                continue;
            if(left[i] + right[i] - 1 >= 3)
                maxlen = max(maxlen, left[i] + right[i] - 1);
        }
        return n - maxlen;
    }
};