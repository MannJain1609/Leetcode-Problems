class Solution {
public:
    bool canJump(vector<int>& nums) {
       int farthest=0;
        
        for(int i=0;i<nums.size()-1;i++){
            if(i+nums[i] > farthest)
                farthest = i+nums[i];
            if(i==farthest)
                break;
        }
               
        return farthest >= nums.size()-1;
    }
};