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
    // bool isEqual(TreeNode* a, TreeNode* b)
    // {
    //     if(a == NULL && b == NULL)
    //         return true;
    //     if(a == NULL || b == NULL)
    //         return false;
    //     if(a->val != b->val)
    //         return false;
    //     return isEqual(a->left,b->left) && isEqual(a->right,b->right);
    // }
    // bool sameStructure(queue<TreeNode*> s, unordered_set<TreeNode*>& dup,  TreeNode* root)
    // {
    //     while(!s.empty())
    //     {
    //         TreeNode* temp = s.front();
    //         s.pop();
    //         if(isEqual(temp,root)) {
    //             dup.insert(temp);
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // void helper(unordered_set<TreeNode*>& dup, queue<TreeNode*>& s, TreeNode* root) {
    //     if(root == NULL)
    //         return;
    //     if(!sameStructure(s,dup,root))
    //         s.push(root);
    //     helper(dup,s,root->left);
    //     helper(dup,s,root->right);
    // }

    string s = "";
    void helper(TreeNode* root) {
        if(root == NULL)
        {
            s+="n.";
            return;
        }
        s+= to_string(root->val) + ".";
        helper(root->left);
        helper(root->right);
    }
    
    string serialize(TreeNode* root) {
        s="";
        helper(root);
        return s;
    }
    void InsertDup(unordered_map<string,TreeNode*>& mp, unordered_set<TreeNode*>& dup, TreeNode* root)
    {
        if(root==NULL)
            return;
        string tree = serialize(root);
        //cout<<tree<<endl;
        if(mp.find(tree)!=mp.end())
            dup.insert(mp[tree]);
        else
            mp.insert({tree,root});
        InsertDup(mp,dup,root->left);
        InsertDup(mp,dup,root->right);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // queue<TreeNode*>s;
        // unordered_set<TreeNode*> dup;
        // helper(dup,s,root);
        // vector<TreeNode*>ans;
        // for(auto it = dup.begin(); it!=dup.end(); it++)
        //     ans.push_back(*it);
        // return ans;
        
        unordered_map<string,TreeNode*>mp;
        unordered_set<TreeNode*>dup;
        vector<TreeNode*>ans;
        InsertDup(mp,dup,root);
        for(auto it = dup.begin(); it!=dup.end(); it++)
            ans.push_back(*it);
        return ans;
    }
};