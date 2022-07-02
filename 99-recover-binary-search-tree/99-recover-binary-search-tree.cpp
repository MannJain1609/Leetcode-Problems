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
    TreeNode* wrong1 = NULL, *wrong2 = NULL,*temp = new TreeNode(INT_MIN);
    void inorder_get(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder_get(root->left);
        //cout<<root->val<<" ";
        if(root->val < temp->val)
        {
            if(wrong1 == NULL) {
                wrong1 = temp;
                wrong2 = root;
            }
            wrong2 = root;
        }
        temp = root;
        inorder_get(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder_get(root);
        int t = wrong1->val;
        wrong1->val = wrong2->val;
        wrong2->val = t;
    }
};