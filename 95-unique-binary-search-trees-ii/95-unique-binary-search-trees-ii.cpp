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
    vector<TreeNode*> generateTrees(int start, int end)
    {
        vector<TreeNode*> tree;
        if(start>end)
        {
            tree.push_back(NULL);
            return tree;
        }
        
        // if(memo[start][end]!=NULL)
        //     return memo[start][end];
        
        for(int i=start; i<=end; i++)
        {
            vector<TreeNode*> left = generateTrees(start,i-1);
            vector<TreeNode*> right = generateTrees(i+1,end);
            
            for(TreeNode* l: left)
            {
                for(TreeNode* r: right)
                {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    tree.push_back(curr);
                }
            }
        }
        //memo[start][end] = tree;
        return tree;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        //vector<vector<vector<TreeNode*>>>memo(n+1,vector<TreeNode*>(n+1, NULL));
        return generateTrees(1,n);
    }
};