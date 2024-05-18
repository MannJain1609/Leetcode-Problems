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
    deque<int>q;
    void BST(TreeNode* root)
    {
        stack<TreeNode*>s;
        TreeNode* curr = root;
        while(curr != NULL || !s.empty())
        {
            if(curr == NULL)
            {
                curr = s.top();
                s.pop();
                q.push_back(curr->val);
                curr = curr->right;
            }
            else {
                s.push(curr);
                curr = curr->left;
            }
        }
    }
    bool findTarget(TreeNode* root, int k) {
        //q contains inorder traversal(sorted)
        BST(root);
        //only one element
        while(q.size() > 1)
        {
            if(q.front() + q.back() == k)
                return true;
            if(q.front() + q.back() < k)
                q.pop_front();
            else
                q.pop_back();
        }
        return false;
    }
};