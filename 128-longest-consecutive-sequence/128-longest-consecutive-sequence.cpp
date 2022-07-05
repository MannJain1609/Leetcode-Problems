class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> seq;
        for(int i=0; i<size; i++)
            seq.insert(nums[i]);
        int maxlen = 0;
        for(int i=0; i<size; i++)
        {
            //current nums[i] element
            int len = 1;
            int num = nums[i];
            //if seq contains num-1, it has alraeady been counted
            if(num!=INT_MIN && !seq.count(num-1))
            {
                while(num!=INT_MAX && seq.count(num+1))
                {
                    len++;
                    num+=1;
                }
                maxlen = max(maxlen,len);
            }
        }
        return maxlen;
    }
};