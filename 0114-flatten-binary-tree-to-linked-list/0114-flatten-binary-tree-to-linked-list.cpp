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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left) {
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = curr->right;
                    curr->right = curr->left;
                    curr->left = NULL;
                    curr = curr->right;
                }
            }
            else {
                curr = curr->right;
            }
        }
    }
};