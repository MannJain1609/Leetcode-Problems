/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // int p_val = p->val;
        // int q_val = q->val;
        // int max_value = max(p_val,q_val);
        // int min_value = min(p_val,q_val);
        // TreeNode* temp = root;
        // while(temp)
        // {
        //     if(temp == p || temp == q || (temp->val > min_value && temp->val < max_value))
        //         return temp;
        //     if(temp->val<min_value)
        //         temp = temp->right;
        //     else
        //         temp = temp->left;
        // }
        // return temp;
        
        //Recursion
        //if both are smaller than root, go to left
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        //if both are greater than root
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        //else root is the LCA
        return root;
    }
};