/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
//     Node* helper(Node* root)
//     {
//         if(root == NULL)
//             return root;
//         TreeNode* left = helper(root->left);
//         TreeNode* right = helper(root->right);
//         if(left)
//             left->next = right;
//     }
    
    void connect(Node* root, Node* parent) {
        if(root == NULL)
            return;
        if(parent == NULL)
            root->next = NULL;
        //if root is left child of parent
        else if(parent->left == root)
            root->next = parent->right;
        //if root is right child of parent
        else if(parent->right == root) {
            if(parent->next)
                root->next = parent->next->left;
            else
                root->next = NULL;
        }
        connect(root->left,root);
        connect(root->right,root);
    }
public:
    Node* connect(Node* root) {
        connect(root,NULL);
        return root;
    }
};