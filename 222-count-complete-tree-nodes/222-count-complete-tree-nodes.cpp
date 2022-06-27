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
    int getleftheight(TreeNode* root)
    {
        TreeNode* curr = root;
        int height = 0;
        while(curr)
        {
            height++;
            curr = curr->left;
        }
        return height;
    }
    
    int getrightheight(TreeNode* root)
    {
        TreeNode* curr = root;
        int height = 0;
        while(curr)
        {
            height++;
            curr = curr->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = getleftheight(root);
        int rh = getrightheight(root);
        
        if(lh == rh)
        {
            //every node has two children including leaf nodes
            return pow(2,lh)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};