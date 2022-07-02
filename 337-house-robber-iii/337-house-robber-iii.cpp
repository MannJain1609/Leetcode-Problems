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
public:
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        //Memoization
        if(mp.find(root)!=mp.end())
            return mp[root];
        
        //root is robbed
        int rob1 = root->val;
        if(root->left)
            rob1+= rob(root->left->left)+rob(root->left->right);
        if(root->right)
            rob1+= rob(root->right->left)+rob(root->right->right);
        
        //root is not robbed
        int rob2 = rob(root->left)+rob(root->right);
        
        mp.insert({root,max(rob1,rob2)});
        return max(rob1,rob2);
    }
};