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

struct IndexedNode {
    int sum,  Min, Max;
    IndexedNode() {
        this->sum = 0;
        this->Min = 100000;
        this->Max = -100000;
    }
    IndexedNode(int sum,int min,int max) {
        this->sum =sum;
        this->Min = min;
        this->Max = max;
    }
};

class Solution {
public:
    int maxSum = 0;
    IndexedNode* help(TreeNode* root)
    {
        if(root == NULL)
            return new IndexedNode();

        IndexedNode* left = help(root->left);
        IndexedNode* right = help(root->right);
        

        if(left == NULL || right == NULL) {
            return NULL;
        }
        
         if(root->left == NULL && root->right == NULL)
        {
            maxSum = max(maxSum, root->val);
            return new IndexedNode(root->val,root->val, root->val);
        }

        if(root->val > left->Max && root->val < right->Min)
        {
            int sum = root->val + left->sum + right->sum;
            maxSum = max(maxSum, sum);
            int Min = min(root->val, left->Min);
            int Max = max(root->val,right->Max);
            IndexedNode* temp = new IndexedNode(sum,Min,Max);
            return temp;
        }
        return NULL;   
        
    }

    // int bstSum(TreeNode* root, int big, int small)
    // {
    //     if(root == NULL)
    //         return 0;
    //     if(root->val >= big || root->val <= small)
    //         return INT_MIN;
    //     if(root->left == NULL && root->right == NULL)
    //         return root->val;
    //     int t1 = bstSum(root->left, root->val,small);
    //     int t2 = INT_MIN;
    //     if(t1 != INT_MIN)
    //         t2 = bstSum(root->right, big, root->val);
    //     if(t2 == INT_MIN)
    //         return INT_MIN;
    //     return root->val + t1 + t2;
    // }
    // void helper(TreeNode* root)
    // {
    //     if(root == NULL)
    //         return;
        
    //     helper(root->left);
    //     helper(root->right);

    //     int temp = bstSum(root,100000,-100000);
    //     //cout<<temp<<endl;
    //     maxSum = max(maxSum, temp);
    // }
    int maxSumBST(TreeNode* root) {
        //helper(root);
        help(root);
        return maxSum;
    }
};