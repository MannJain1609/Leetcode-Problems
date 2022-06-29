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
    bool findTarget(TreeNode* root, int k) {
        deque<int> bst;
        //Iterative inorder
        stack<TreeNode*> temp;
        TreeNode* curr = root;
        while(curr || !temp.empty())
        {
            if(curr == NULL)
            {
                curr = temp.top();
                temp.pop();
                bst.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                temp.push(curr);
                curr = curr->left;
            }
        }
        while(!bst.empty())
        {
            if(bst.front() == bst.back())
                return false;
            if(bst.front() + bst.back() == k)
                return true;
            if(bst.front() + bst.back() > k)
                bst.pop_back();
            else
                bst.pop_front();
        }
        return false;
    }
};