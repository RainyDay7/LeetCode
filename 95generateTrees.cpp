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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode* > ans ;
        if(n==0) return ans;
        return getAns(1,n);
    }

    vector<TreeNode*> getAns(int start, int end) {
        vector<TreeNode*> ans;
        //��ʱû�����֣��� null ��������
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }
        //ֻ��һ�����֣���ǰ������Ϊһ������������
        if (start == end) {
            TreeNode* tree = new TreeNode(start);
            ans.push_back(tree);
            return ans;
        }
        //����ÿ��������Ϊ���ڵ�
        for(int i=start; i<=end; i++){
            //�õ����п��ܵ�������
            vector<TreeNode*> leftTrees = getAns(start, i - 1);
            //�õ����п��ܵ�������
            vector<TreeNode*> rightTrees = getAns(i + 1, end);
            //�������������������
            for (TreeNode* leftTree : leftTrees) {
                for (TreeNode* rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    //���뵽���ս����
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
