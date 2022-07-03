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
    int sum = 0;
    TreeNode* sumLeaves(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode* Left = sumLeaves(root->left);
        TreeNode* Right = sumLeaves(root->right);
        if(Left)
        {
            if(Left->left == NULL && Left->right == NULL)
                sum+=Left->val;
        }
        return root;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sumLeaves(root);
        return sum;
    }
};