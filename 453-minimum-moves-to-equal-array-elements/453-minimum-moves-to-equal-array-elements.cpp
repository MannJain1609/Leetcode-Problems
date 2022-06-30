class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Incrementing n-1 elements of array by 1 to make equal array elements
        // This is similar to
        // Decrementing 1 element of array by 1 to make all elements equal
        
        // Decrement each element to reach the smallest element in array
        // Moves required for each index will be (value-smallest)
        // Summing for all 
        // (nums[0]-smallest) + (nums[1]-smallest) + (nums[2]-smallest) + ...........
        // Equivalent to (Sum of array - n*smallest)
        int minimum = nums[0], sum = nums[0];
        int size = nums.size();
        for(int i=1; i<size; i++)
        {
            sum+= nums[i];
            minimum = min(minimum, nums[i]);
        }
        return sum - (minimum*size);
    }
};