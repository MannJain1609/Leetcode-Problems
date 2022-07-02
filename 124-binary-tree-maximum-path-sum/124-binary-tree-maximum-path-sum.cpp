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
    int maxSum = INT_MIN;
    int PathSum(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int left = PathSum(root->left);
        int right = PathSum(root->right);
        int sum = max(root->val,root->val+max(left,right));
        //cout<<sum<<" ";
        maxSum = max(maxSum,root->val);
        maxSum = max(maxSum, max(root->val+left+right,max(root->val+left,root->val+right)));
        root->val = sum;
        return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        PathSum(root);
        return maxSum;
    }
};