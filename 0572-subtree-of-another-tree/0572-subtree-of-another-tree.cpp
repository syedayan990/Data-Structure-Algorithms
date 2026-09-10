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
    
    bool isIdentical(TreeNode* p , TreeNode* q){
        if(p == nullptr || q == nullptr){
        return p == q;
       }

       bool leftIdentical = isIdentical(p->left , q->left);
       bool rightIdentical = isIdentical(p->right , q->right);
       return leftIdentical && rightIdentical && (p->val == q->val) ;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

       if(root == nullptr || subRoot == nullptr){
        return root == subRoot;
       }

        if(root->val == subRoot->val && isIdentical(root , subRoot)){
            return true;
        }

       bool leftSame = isSubtree(root->left , subRoot);
        bool rightSame = isSubtree(root->right , subRoot);
        return leftSame || rightSame;
    }
};