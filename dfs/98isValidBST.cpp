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
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MAX,LONG_MIN);
    }

    bool dfs(TreeNode* root, long max,long min){
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        else return (dfs(root->left,root->val,min) && dfs(root->right,max,root->val));
    }
};

