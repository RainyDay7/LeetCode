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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        
        q.push(root);
        int order=1;//0´Ó×óÍùÓÒ£¬1´ÓÓÒÍù×ó
        while(!q.empty()){
            vector<int> v;
            int len = q.size();
            while(len--){
                TreeNode *t = q.front();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                v.push_back(t->val);
                q.pop();
            }
            if(order==-1){
                reverse(v.begin(), v.end());
            }
            order = -order;
            res.push_back(v);
            }
        return res;
    }
};
