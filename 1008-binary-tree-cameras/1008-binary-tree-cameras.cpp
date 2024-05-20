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
    int camera = 0;
    //0->camera installed, 1-> no camera, being watched, 2->no camera, not being watched
    int installCameras(TreeNode* root)
    {
        if(root == NULL)
            return 1;
        int left = installCameras(root->left);
        int right = installCameras(root->right);

        if(left == 2 || right == 2) {
            camera++;
            return 0;
        }
        if(left == 0 || right == 0) {
            return 1;
        }
        return 2;
    }
    int minCameraCover(TreeNode* root) {
        if(installCameras(root) == 2)
            camera++;
        return camera;
    }
};