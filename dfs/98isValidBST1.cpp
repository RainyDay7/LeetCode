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
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        pre=NULL;
        return dfs(root);
    }
    
    bool dfs(TreeNode* root){
        if(!root) return true;
        if(!dfs(root->left)) return false;//判断左子树
        if(pre && pre->val>=root->val) return false;//判断前值是否大于在此之前的最大值
        pre=root;
        if(!dfs(root->right)) return false;//判断右子树
        return true;
    }
};

