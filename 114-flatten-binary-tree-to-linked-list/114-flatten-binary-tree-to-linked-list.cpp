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
    void helper(TreeNode* root) {
        queue<TreeNode*>q;
        stack<TreeNode*> temp;
        TreeNode* curr = root;
        while(curr || !temp.empty())
        {
            if(curr == NULL)
            {
                curr = temp.top();
                temp.pop();
                curr = curr->right;
            }
            else
            {
                q.push(curr);
                temp.push(curr);
                curr = curr->left;
            }
        }
        if(q.empty())
            return;
        TreeNode* r = q.front();
        q.pop();
        while(!q.empty())
        {
            r->left = NULL;
            r->right = q.front();
            q.pop();
            r = r->right;
        }
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};