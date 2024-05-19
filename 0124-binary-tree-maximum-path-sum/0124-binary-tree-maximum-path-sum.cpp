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
    int maxSum = INT_MIN;
    int helper(TreeNode* root)
    {
        if(root == NULL)
            return INT_MIN;
        // if(root->left == NULL && root->right == NULL) {
        //     maxSum = max(maxSum, root->val);
        //     return root->val;
        // }
        int left = helper(root->left);
        int right = helper(root->right);

        int ans = root->val;
        if(left!= INT_MIN)
            ans = max(ans, root->val + left);
        if(right != INT_MIN)
            ans = max(ans,root->val + right);
        maxSum = max(maxSum, ans);
        if(left != INT_MIN && right != INT_MIN)
            maxSum = max(maxSum, root->val + left+right);
        return ans;
    
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};