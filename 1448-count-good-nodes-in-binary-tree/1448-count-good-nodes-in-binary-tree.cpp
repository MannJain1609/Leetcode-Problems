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
    int preorder(TreeNode* root,int max)
    {
        if(root==NULL)
            return 0;
        if(root->val >= max)
            return 1 + preorder(root->left,root->val) + preorder(root->right, root->val);
        return preorder(root->left,max)+preorder(root->right,max);
    }
public:
    int goodNodes(TreeNode* root) {
        return preorder(root,INT_MIN);
    }
};