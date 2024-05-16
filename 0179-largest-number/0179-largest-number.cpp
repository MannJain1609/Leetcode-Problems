class Solution {
public:
    static bool cmp(int& a, int& b) {
        string x = to_string(a);
        string y = to_string(b);
        return x+y > y+x;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        string s= "";
        if(nums[0] == 0)
            return "0";
        for(int i=0; i<n; i++)
        {
            s += to_string(nums[i]);
        }
        return s;
    }
};