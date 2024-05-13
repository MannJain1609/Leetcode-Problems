class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int y = -1, z = -1, cy = 0, cz = 0;
        for(int num : nums)
        {
            if(num == y)
                cy++;
            else if(num == z)
                cz++;
            else if(cy == 0)
            {
                cy = 1;
                y = num;
            }
            else if(cz == 0)
            {
                cz = 1;
                z = num;
            }
            else {
                cy --;
                cz --;
            }
        }
        cy = 0, cz = 0;
        for(int num : nums)
        {
            if(num == y)
                cy++;
            else if(num == z)
                cz++;
        }
        vector<int> ans;
        int cnt = nums.size()/3;
        if(cy > cnt) ans.push_back(y);
        if(cz > cnt) ans.push_back(z);
        return ans;
    }
};