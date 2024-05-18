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
    TreeNode* w1 = NULL;
    TreeNode* w2 = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);

    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder(root->left);

        if(root->val < prev->val) {
            if(w1 == NULL) {
                w1 = prev;
                w2 = root;
            }
            else {
                w2 = root;
            }
        }
        prev = root;
        inorder(root->right);
        
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = w1->val;
        w1->val = w2->val;
        w2->val = temp;

    }
};