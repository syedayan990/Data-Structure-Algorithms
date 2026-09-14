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
    int PrevOrder = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        if (root->left != nullptr) {
            int leftAns = kthSmallest(root->left, k);
            if (leftAns != -1) {
                return leftAns;
            }
        }
        if (PrevOrder + 1 == k) {
            return root->val;
        }
        PrevOrder = PrevOrder + 1;

        if (root->right != nullptr) {
            int rightAns = kthSmallest(root->right, k);
            if (rightAns != -1) {
                return rightAns;
            }
        }

        return -1;
    }
};