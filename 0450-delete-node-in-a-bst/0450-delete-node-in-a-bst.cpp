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
    int successor(TreeNode* root)
    {
        TreeNode* temp = root->right;
        while(temp->left != NULL)
            temp = temp->left;
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else //root is to be deleted
        {
            if(root->left == NULL)
                return root->right;
            if(root->right == NULL)
                return root->left;
            root->val = successor(root);
            root->right = deleteNode(root->right,root->val);
        }
        return root;
    }
};