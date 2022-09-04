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
    class IndexedNode {
    public:
        TreeNode* root;
        int row,col;
        IndexedNode(TreeNode* root, int row, int col)
        {
            this->root = root;
            this->row = row;
            this->col = col;
        }
    };
    static bool cmp (IndexedNode& a, IndexedNode &b) {
        if(a.row == b.row)
            return a.root->val < b.root->val;
        return a.row<b.row;
    }
    void verticalTraversal(vector<vector<int>>& ans,TreeNode* root)
    {
        if(root == NULL)
            return;
        queue<IndexedNode> q;
        map<int,vector<IndexedNode>>mp;
        q.push({root,0,0});
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                IndexedNode T = q.front();
                q.pop();
                mp[T.col].push_back(T);
                if(T.root->left)
                    q.push({T.root->left,T.row+1,T.col-1});
                if(T.root->right)
                    q.push({T.root->right,T.row+1,T.col+1});
            }
        }
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            vector<IndexedNode>temp = it->second;
            sort(temp.begin(),temp.end(),cmp);
            vector<int> t;
            for(IndexedNode T : temp)
            {
                t.push_back(T.root->val);
            }
            ans.push_back(t);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        verticalTraversal(ans,root);
        return ans;
    }
};