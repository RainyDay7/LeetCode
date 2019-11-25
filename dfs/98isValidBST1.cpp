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
        if(!dfs(root->left)) return false;//�ж�������
        if(pre && pre->val>=root->val) return false;//�ж�ǰֵ�Ƿ�����ڴ�֮ǰ�����ֵ
        pre=root;
        if(!dfs(root->right)) return false;//�ж�������
        return true;
    }
};

