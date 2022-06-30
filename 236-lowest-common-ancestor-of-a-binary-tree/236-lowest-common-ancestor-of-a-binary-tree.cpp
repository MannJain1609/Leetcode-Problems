/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //It root is p or q, root is LCA
        //If root is NULL, return NULL
        if(root == NULL || root==p || root==q)
            return root;
        //Postorder
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        //We return p or q if found , else null
        //if both left and right are not null, then that root is the LCA
        //otherwise it will directly return p or q which lies above. In that case p or q will be LCA
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        //if both are not NULL, root is LCA
        return root;
    }
};