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
    void helper(vector<vector<int>>& ans,TreeNode* root, int depth)
    {
        if(!root)
            return;
        if(ans.size()==depth)
            ans.push_back(vector<int> ());
        ans[depth].push_back(root->val);
        helper(ans,root->left, depth+1);
        helper(ans,root->right,depth+1);
    }
public:
/*    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>level;
            int size = q.size();
            while(size)
            {
                root = q.front();
                level.push_back(root->val);
                q.pop();
                
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                size--;
            }
            ans.push_back(level);
        }
        return ans;
    }
};*/

 vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(ans,root,0);
        return ans;
    }
};