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

    int height(TreeNode* node) {
        
        if(node == nullptr)
        return -1;
        
        return 1+max(height(node->left),height(node->right));
        
    }

    void find(TreeNode *root, int h, int &sum, int pos) {

        if(!root)
        return;

        if(pos == h) {
            sum = sum + root->val;
        }

        find(root->left,h,sum,pos+1);
        find(root->right,h,sum,pos+1);
    }

    int deepestLeavesSum(TreeNode* root) {

        int h = height(root);

        int sum = 0;
        find(root,h,sum,0);

        return sum;
    }

};