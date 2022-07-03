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
    int minDiff = INT_MAX,prev = -1;
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        if(prev == -1)
            prev = root->val;
        else
        {
            minDiff = min(minDiff,root->val-prev);
            prev = root->val;
        }
        inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};