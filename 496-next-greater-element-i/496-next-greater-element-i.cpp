class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int> mp;
        int size1 = nums1.size();
        int size2 = nums2.size();
        for(int i=size2-1; i>=0; i--)
        {
            while(!s.empty() && s.top()<=nums2[i])
                s.pop();
            if(s.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        vector<int>ans(size1);
        for(int i=0; i<size1; i++)
        {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};