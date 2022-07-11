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
    void RightView(vector<int>& ans, TreeNode* root)
    {
        if(root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                if(i==size-1)
                    ans.push_back(temp->val);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        RightView(ans,root);
        return ans;
    }
};