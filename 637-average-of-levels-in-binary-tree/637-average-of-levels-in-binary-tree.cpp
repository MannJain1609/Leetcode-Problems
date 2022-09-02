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
    void bfs(TreeNode* root, vector<double>& ans) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            double avg = 0;
            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                avg+= temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            avg = avg/size;
            ans.push_back(avg);
        }
        
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        bfs(root,ans);
        return ans;
    }
};