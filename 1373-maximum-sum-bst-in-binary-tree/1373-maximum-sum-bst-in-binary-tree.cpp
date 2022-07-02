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
class IndexedNode{
public:
    TreeNode* root;
    int Min,Max;
    bool BST;
    IndexedNode(TreeNode* root, int Min, int Max, bool BST)
    {
        this->root = root;
        this->Min = Min;
        this->Max = Max;
        this->BST = BST;
    }
};
    //empty BST, ans will never be negative
    //Postorder
    int max_sum = 0;
    IndexedNode MaxSumBST(TreeNode* root)
    {
        //Empty BST
        if(root == NULL)
            return {root,INT_MIN,INT_MAX,true};
        //leaf node is a BST
        if(root->left == NULL && root->right == NULL) {
            max_sum = max(max_sum,root->val);
            return {root,root->val,root->val,true};
        }
        IndexedNode Left = MaxSumBST(root->left);
        IndexedNode Right = MaxSumBST(root->right);
        if(!Left.BST || !Right.BST)
            return {root,root->val,root->val,false};
        //Subtree is a BST
        int minimum = root->val, maximum = root->val;
        bool isBST = true;
        if(Left.root) {
            minimum = min(minimum,Left.Min);
            if(root->val <= Left.Max)
                isBST = false;
        }
        if(Right.root) {
            maximum = max(maximum,Right.Max);
            if(root->val >= Right.Min)
                isBST = false;
        }
        IndexedNode temp = {root,minimum,maximum,isBST};
        if(!isBST)
            return temp;
        if(root->left)
            root->val += root->left->val;
        if(root->right)
            root->val+= root->right->val;
        max_sum = max(max_sum,root->val);
        //cout<<"val: "<<root->val<<" ";
        return temp;
    }
public:
    int maxSumBST(TreeNode* root) {
        MaxSumBST(root);
        return max_sum;
    }
};