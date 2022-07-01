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
    TreeNode* buildBST(vector<int>& preorder, int preStart, int preEnd) {
        if(preStart > preEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int val = preorder[preStart];
        int index = preStart+1;
        while(index<=preEnd && preorder[index]<val)
            index++;
        //int count = index-preStart-1;
        root->left = buildBST(preorder,preStart+1,index-1);
        root->right = buildBST(preorder,index,preEnd);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        return buildBST(preorder,0,size-1);
    }
};