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
    TreeNode* BuildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& Inorder,
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int root_val = preorder[0];
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int size = preorder.size();
        unordered_map<int,int>Inorder;
        for(int i=0; i<size; i++)
        {
            Inorder[inorder[i]] = i;
        }
        return BuildTree(preorder,inorder,Inorder,size-1,0,size-1);
    }
};