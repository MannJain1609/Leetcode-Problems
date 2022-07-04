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
    int kth_min = -1,i=0;
    void inorder(TreeNode* root, int k) {
        if(root==NULL || kth_min!=-1)
            return;
        inorder(root->left,k);
        i++;
        if(i == k)
            kth_min = root->val;
        inorder(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return kth_min;
    }
};