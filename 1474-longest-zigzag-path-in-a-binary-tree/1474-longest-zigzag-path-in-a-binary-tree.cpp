/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = ZigZag(root->left, true);
        int right = ZigZag(root->right, false);
        ans = max(ans, max(left,right));
        return ans;
    }
    //isLeft to represent previously left or not 
    int ZigZag(TreeNode* root, bool isLeft)
    {
        if(root == NULL)
            return 0;
        
        int left = ZigZag(root->left, true);
        int right = ZigZag(root->right,false);

        ans = max(ans, max(left,right));
        int curr = 0;
        if(isLeft)
         curr = 1 + right;
        else 
            curr = 1+ left;
        return curr;
    }
};