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
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b)
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    void bfs(map<int,vector<int>>& mp, TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            vector<pair<int,int>>temp;
            for(int i=0; i<size; i++)
            {
                TreeNode* n = q.front().first;
                int col = q.front().second;
                q.pop();
                temp.push_back({col,n->val});
                if(n->left)
                    q.push({n->left, col -1});
                if(n->right)
                    q.push({n->right, col+1});
            }
            sort(temp.begin(), temp.end(), cmp);
            for(pair<int,int>& v: temp)
            {
                mp[v.first].push_back(v.second);
            }
            //level ++;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL)
            return {{}};
        vector<vector<int>>ans;
        map<int,vector<int>>mp;
        bfs(mp,root);
        for(auto it = mp.begin(); it!= mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};