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
    bool isbalanced = true;
    int getHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    void preorder(TreeNode* root) {
        if(root == NULL || !isbalanced)
            return;
        if(abs(getHeight(root->left)-getHeight(root->right))>=2)
            isbalanced = false;
        preorder(root->left);
        preorder(root->right);
    }
public:
    bool isBalanced(TreeNode* root) {
        preorder(root);
        return isbalanced;
    }
};