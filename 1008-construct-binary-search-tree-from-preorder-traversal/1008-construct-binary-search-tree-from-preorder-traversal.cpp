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
    TreeNode* buildBST(vector<int>& preorder, int size) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<size; i++)
        {
            int val = preorder[i];
            TreeNode* temp = root;
            TreeNode* ins = new TreeNode(val);
            while(true)
            {
                if(temp->val < val)
                {
                    if(temp->right)
                        temp = temp->right;
                    else {
                        temp->right = ins;
                        break;
                    }
                }
                else
                {
                    if(temp->left)
                        temp = temp->left;
                    else {
                        temp->left = ins;
                        break;
                    }
                }
            }
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        return buildBST(preorder,size);
    }
};