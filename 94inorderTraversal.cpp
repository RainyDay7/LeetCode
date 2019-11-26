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
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return v;
        inorderTraversal1(root);
        return v;
      }
    void inorderTraversal1(TreeNode* root) {
        if(root->left) inorderTraversal1(root->left);
        v.push_back(root->val);
        if(root->right) inorderTraversal1(root->right);
    }
};
