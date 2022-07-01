/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
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
public:
    int index = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        helper(root);
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int size = data.size();
        string num = "";
        while(index<size && data[index]!='.') {
            num+=data[index];
            index++;
        }
        index++;
        TreeNode* root;
        if(num == "n") {
            root = NULL;
            return root;
        }
        else
            root = new TreeNode(stoi(num));
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));