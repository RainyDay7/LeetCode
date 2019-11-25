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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return (fun(root->left, root->right));
    }
    bool fun(TreeNode *left, TreeNode *right){
        if (!left && !right) return true;
        if (left && !right || !left && right || left->val != right->val) return false;
        return (fun(left->left, right->right) && fun(left->right, right->left));
    }
};
