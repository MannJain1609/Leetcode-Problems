/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isTree(ListNode* head, TreeNode* root) {
        if(head == NULL)
            return true;
        if(root == NULL)
            return false;
        if(root->val == head->val) {
            return isTree(head->next, root->left) || isTree(head->next, root->right);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == NULL)
            return true;
        if(root == NULL)
            return false;
        bool t1 = false, t2 = false, t3 = false, t4 = false;
        if(root->val == head->val)
        {
            t1 = isTree(head->next, root->left);
            if(t1)
                return true;
            t1 = isTree(head->next, root->right);
        }
        if(t1)
            return true;
        t2 = isSubPath(head, root->left);
        if(t2)
            return true;
        t3 = isSubPath(head, root->right);
        if(t3)
            return true;
        return false;
    }
};