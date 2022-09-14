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
    
    int count = 0;
    bool isPalindrome(vector<int>& arr)
    {
        int odds = 0;
        for(int i=0; i<10; i++)
        {
            if(arr[i]%2!=0)
                odds++;
            if(odds>1)
                return false;
        }
        return true;
    }
    void helper(TreeNode* root, vector<int>& arr) {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            arr[root->val]++;
            if(isPalindrome(arr))
                count++;
            arr[root->val]--;
            return;
        }
        arr[root->val]++;
        helper(root->left, arr);
        helper(root->right, arr);
        arr[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        //int arr[10] = {0};
        vector<int>arr(10,0);
        helper(root, arr);
        return count;
    }
};