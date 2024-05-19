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
    string postorder(TreeNode* root, unordered_map<string, vector<TreeNode*>>& mp)
    {
        if(root == NULL)
            return "n.";
        string left = postorder(root->left, mp);
        string right = postorder(root->right, mp);

        string st = to_string(root->val) + " " + left + right;
        if(root != NULL)
            mp[st].push_back(root);
        return st;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*> >mp;
        postorder(root,mp);
        vector<TreeNode*>ans;
        for(auto it = mp.begin(); it!= mp.end(); it++)
        {
            if(it->second.size() >= 2)
            {
                ans.push_back(it->second[0]);
            }
        }
        return ans;
    }
};