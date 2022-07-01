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
    TreeNode* BuildTree(vector<int>& preorder, vector<int>& postorder, unordered_map<int,int>& 
                        Postorder, int preStart, int preEnd, int postStart, int postEnd)
    {
        if(preStart > preEnd || postStart > postEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        if(preStart == preEnd)
            return root;
        int index = Postorder[preorder[preStart+1]];
        int countOfElements = index - postStart + 1;
        root->left  = BuildTree(preorder,postorder,Postorder,preStart+1,preStart+countOfElements,
                               postStart,index);
        root->right = BuildTree(preorder,postorder,Postorder,preStart+countOfElements+1,preEnd,
                               index+1,postEnd-1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int size = preorder.size();
        //For O(1) search operation
        unordered_map<int,int>Postorder;
        for(int i=0; i<size; i++)
        {
            Postorder[postorder[i]] = i;
        }
        return BuildTree(preorder,postorder,Postorder,0,size-1,0,size-1);
    }
};