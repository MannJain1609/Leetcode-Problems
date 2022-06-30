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
    int preStart = 0;
    TreeNode* BuildTree(vector<int>& preorder, vector<int>& inorder, map<int,int>& Inorder,
                        TreeNode* root, int preEnd, int inStart, int inEnd)
    {
        if(preStart<=preEnd)
        {
            if(inStart > inEnd) {
                //preStart--;
                return NULL;
            }
            TreeNode* ins = new TreeNode(preorder[preStart]);
            if(root == NULL)
              root = ins;
            int index = Inorder[preorder[preStart]];
            preStart++;
            root->left = BuildTree(preorder,inorder,Inorder,
                                   root->left,preEnd,inStart, index-1);
            root->right = BuildTree(preorder,inorder,Inorder,
                                    root->right,preEnd,index+1,inEnd);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preSize = preorder.size();
        int inSize = inorder.size();
        map<int,int>Inorder;
        for(int i=0; i<inSize; i++)
        {
            Inorder[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        BuildTree(preorder,inorder,Inorder,root, preSize-1,0,inSize-1);
        return root;
    }
};