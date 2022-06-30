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
    int postStart = 0;
    TreeNode* BuildTree(vector<int>& postorder, vector<int>& inorder, map<int,int>& Inorder,
                        int postEnd, int inStart, int inEnd)
    {
        if(postStart<=postEnd)
        {
            if(inStart > inEnd) {
                //preStart--;
                return NULL;
            }
            TreeNode* root = new TreeNode(postorder[postStart]);
            int index = Inorder[postorder[postStart]];
            postStart++;
            root->right = BuildTree(postorder,inorder,Inorder,
                                    postEnd,index+1,inEnd);
            root->left = BuildTree(postorder,inorder,Inorder,
                                   postEnd,inStart, index-1);
            return root;
        }
        return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postSize = postorder.size();
        int inSize = inorder.size();
        map<int,int>Inorder;
        for(int i=0; i<inSize; i++)
        {
            Inorder[inorder[i]] = i;
        }
        reverse(postorder.begin(), postorder.end());
        return BuildTree(postorder,inorder,Inorder,postSize-1,0,inSize-1);
    }
};