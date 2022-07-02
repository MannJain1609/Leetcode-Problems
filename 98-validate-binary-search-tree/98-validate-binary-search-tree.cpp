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
private:
    bool isBST(TreeNode* root, long Min, long Max)
    {
        if(root == NULL)
            return true;
        if(root->val <= Min || root->val >= Max)
            return false;
        return isBST(root->left,Min,root->val) && isBST(root->right,root->val,Max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root,(long)INT_MIN-1,(long)INT_MAX+1);
    }
};