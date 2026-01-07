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

    int find(TreeNode *root, int &ans) {
        
        if(!root) 
        return 0;

        int left = find(root->left,ans);
        int right = find(root->right,ans);

        int leftans = 0;
        int rightans = 0;

        if(root->left && root->left->val == root->val) {
            leftans = left + 1;
        }

        if(root->right && root->right->val == root->val) {
            rightans = right + 1;
        }

        ans = max(ans,(leftans+rightans));
        return max(leftans,rightans);
    }

    int longestUnivaluePath(TreeNode* root) {
        
        int ans = 0;
        find(root,ans);

        return ans;

    }
};