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
    bool isNull = false;
    void postorder(TreeNode* parent, TreeNode* root)
    {
        if(root == NULL)
            return;
        postorder(root,root->left);
        postorder(root,root->right);
        if(root->val!=1 && root->left == NULL && root->right == NULL)
        {
            if(parent==NULL)
            {
                isNull = true;
                return;
            }
            else if(root == parent->left)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        postorder(NULL, root);
        if(isNull)
            return NULL;
        return root;
    }
};