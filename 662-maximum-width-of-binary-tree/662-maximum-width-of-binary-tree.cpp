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
        unsigned long long index;
        IndexedNode(TreeNode* root, unsigned long long index) {
            this->root = root;
            this->index = index;
        }
    };
    int bfs(TreeNode* root) {
        queue<IndexedNode>q;
        q.push({root,1});
        //Root of tree node- level 1
        int width = 1;
        while(!q.empty())
        {
            int size = q.size();
            unsigned long long first,last;
            for(int i =0; i<size; i++)
            {
                IndexedNode T = q.front();
                q.pop();
                if(i==0)
                    first = T.index;
                if(i==size-1)
                    last = T.index;
                if(T.root->left)
                {
                    q.push({T.root->left,2*T.index});
                }
                if(T.root->right)
                {
                    q.push({T.root->right, 2*T.index+1});
                }
            }
            width = max(width, (int)(last-first+1));
        }
        return width;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};