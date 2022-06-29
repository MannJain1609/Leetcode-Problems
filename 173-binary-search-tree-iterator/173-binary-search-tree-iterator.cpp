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
class BSTIterator {
public:
    queue<int>s;
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> temp;
        TreeNode* curr = root;
        while(curr || !temp.empty())
        {
            if(curr == NULL)
            {
                curr = temp.top();
                temp.pop();
                s.push(curr->val);
                curr = curr->right;
            }
            else
            {
                temp.push(curr);
                curr = curr->left;
            }
        }
    }
    
    int next() {
        int x = s.front();
        s.pop();
        return x;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */