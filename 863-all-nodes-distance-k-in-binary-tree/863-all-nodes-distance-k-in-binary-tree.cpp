/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void helper( map<TreeNode*, bool>& visited, 
                map<TreeNode*, TreeNode*>& parent, TreeNode* root) 
    {
        if(root == NULL)
            return;
        visited[root] = false;
        if(root->left)
            parent[root->left] = root;
        if(root->right)
            parent[root->right] = root;
        helper(visited,parent,root->left);
        helper(visited,parent,root->right);
    }
    
    void bfs(vector<int>& ans, map<TreeNode*, TreeNode*>& parent, map<TreeNode*, bool>& visited, 
             TreeNode* root, TreeNode* target, int k)
    {
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        k++;
        while(!q.empty())
        {
            int size = q.size();
            k--;
            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(k==0)
                    ans.push_back(temp->val);
                else
                {
                    if(temp!=root && !visited[parent[temp]]) {
                        q.push(parent[temp]);
                        visited[parent[temp]] = true;
                    }
                    if(temp->left && !visited[temp->left]) {
                        q.push(temp->left);
                        visited[temp->left] = true;
                    }
                    if(temp->right && !visited[temp->right]) {
                        q.push(temp->right);
                        visited[temp->right] = true;
                    }
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> parent;
        map<TreeNode*, bool> visited;
        helper(visited,parent,root);
        bfs(ans,parent,visited,root,target,k);
        return ans;
    }
};