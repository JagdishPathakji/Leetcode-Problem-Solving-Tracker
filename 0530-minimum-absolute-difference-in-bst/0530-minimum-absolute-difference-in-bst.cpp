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

    void find(TreeNode *root, int &diff, int &prev) {

        if(!root) return;

        find(root->left,diff,prev);
        if(prev != -1) {
            diff = min(diff,abs(root->val-prev));
        }
        prev = root->val;
        find(root->right,diff,prev);
    }

    int getMinimumDifference(TreeNode* root) {
        
        int diff = INT_MAX;
        int prev = -1;
        find(root,diff,prev);

        return diff;
    }

};