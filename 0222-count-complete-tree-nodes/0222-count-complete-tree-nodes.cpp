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
    int count = 0;
    int helper(TreeNode* root)
    {
        if(root == NULL)
            return 1;
        
        int left = helper(root->left);
        int right = helper(root->right);
        if(left == 1 && right == 1)  {
            count ++;
            return 1;
        }
        return 0;
    }
    int countNodes(TreeNode* root) {
        helper(root);
        return count;
    }
};