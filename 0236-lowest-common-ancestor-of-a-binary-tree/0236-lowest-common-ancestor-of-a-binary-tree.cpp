/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        if(root == p || root == q){
            return root;
        }

        TreeNode* LeftLCA = lowestCommonAncestor(root->left , p , q);
        TreeNode* RightLCA = lowestCommonAncestor(root->right , p , q);

        if(LeftLCA && RightLCA){
            return root;
        }
        else if(LeftLCA != nullptr){
            return LeftLCA;
        }
        else{
            return RightLCA;
        }
    }
};