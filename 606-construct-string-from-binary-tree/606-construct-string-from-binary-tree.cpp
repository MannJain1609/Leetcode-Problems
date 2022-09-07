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
    void preorder(TreeNode* root, TreeNode* parent,string& ans)
    {
        if(root == NULL)
        {
            if(parent==NULL)
                return;
            if(root == parent->left && parent->right!=NULL)
                ans+= "()";
            return;
        }
        if(ans!="")
            ans+= '(';
        ans+= to_string(root->val);
        preorder(root->left,root,ans);
        preorder(root->right,root,ans);
        ans+= ')';
        
    }
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        preorder(root,NULL,ans);
        ans.resize(ans.size()-1);
        return ans;
    }
};