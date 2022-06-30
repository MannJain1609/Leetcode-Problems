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
                        int preEnd, int inStart, int inEnd)
    {
        if(preStart<=preEnd)
        {
            if(inStart > inEnd) {
                //preStart--;
                return NULL;
            }
            TreeNode* root = new TreeNode(preorder[preStart]);
            int index = Inorder[preorder[preStart]];
            preStart++;
            root->left = BuildTree(preorder,inorder,Inorder,
                                   preEnd,inStart, index-1);
            root->right = BuildTree(preorder,inorder,Inorder,
                                    preEnd,index+1,inEnd);
            return root;
        }
        return NULL;
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
        return BuildTree(preorder,inorder,Inorder,preSize-1,0,inSize-1);
    }
};