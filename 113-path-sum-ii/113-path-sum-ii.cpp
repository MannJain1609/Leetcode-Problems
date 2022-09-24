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
    void helper(vector<vector<int>>& ans, vector<int>& temp, TreeNode* root, int targetSum) {
        if(root == NULL)
            return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && targetSum==root->val) {
                ans.push_back(temp);
        }
        helper(ans,temp,root->left,targetSum-root->val);
        helper(ans,temp,root->right,targetSum-root->val);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>temp;
        helper(ans,temp, root,targetSum);
        return ans;
    }
};