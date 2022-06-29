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
        vector<int> bst;
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
        int i=0,j=bst.size()-1;
        while(i<j)
        {
            if(bst[i] + bst[j] == k)
                return true;
            if(bst[i] + bst[j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
};