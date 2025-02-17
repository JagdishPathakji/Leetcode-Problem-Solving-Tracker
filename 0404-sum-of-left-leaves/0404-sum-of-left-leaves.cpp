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

    void find(TreeNode *root, int &sum) {

        if(root == nullptr)
        return;

        if(root->left and root->left->left == nullptr) {
            sum = sum + root->left->val;
        }

        find(root->left,sum);
        find(root->right,sum);
        
    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0;
        find(root,sum);

        return sum;
    }
};