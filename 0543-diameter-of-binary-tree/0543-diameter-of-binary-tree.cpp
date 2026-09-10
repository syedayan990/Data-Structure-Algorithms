/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // int height(TreeNode* root){
    //         if(root == nullptr){
    //             return 0;
    //         }

    //         int leftHt = height(root->left);
    //         int rightHt = height(root->right);
    //         return max(leftHt , rightHt) + 1;
    //     };

    //     int diameterOfBinaryTree(TreeNode* root) {
    //         if(root == nullptr){
    //             return 0;
    //         }

    //         int leftDiam = diameterOfBinaryTree(root->left);
    //         int rightDiam = diameterOfBinaryTree(root->right);
    //         int currDiam = height(root->left) + height(root->right);
    //         int maxDiam = max(currDiam , max(leftDiam, rightDiam));

    //         return maxDiam;

    int ans = 0;
    int height(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int leftdiam = height(root->left);
        int rightdiam = height(root->right);
        int currdiam = (leftdiam + rightdiam);

        ans = max(currdiam, ans);
        return max(leftdiam, rightdiam) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};