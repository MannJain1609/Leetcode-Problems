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
    void sumWays(TreeNode* root, long long targetSum) {
        if(targetSum == 0)
            count++;
        if(root->left)
            sumWays(root->left, targetSum - (long long)root->left->val);
        if(root->right)
            sumWays(root->right, targetSum - (long long)root->right->val);
    }
    void helper(TreeNode* root, int targetSum) {
        if(root == NULL)
            return;
        sumWays(root, (long long)targetSum - root->val);
        helper(root->left, targetSum);
        helper(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        helper(root,targetSum);
        return count;
    }
};