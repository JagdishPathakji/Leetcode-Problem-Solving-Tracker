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
    void find(TreeNode *root, int &sum, int value) {

        if(!root) {
            return;
        }

        value = value * 10 + root->val;

        if(!root->left and !root->right) {
            sum = sum + value;
            return;
        }

        find(root->left,sum,value);
        find(root->right,sum,value);

    }

    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        int value = 0;
        find(root,sum,value);

        return sum;
    }
};