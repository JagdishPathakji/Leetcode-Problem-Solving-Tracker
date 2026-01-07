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

        int one = left + root->val;
        int two = right + root->val;
        int three = root->val + left + right;
        int four = root->val;

        ans = max({ans,one,two,three,four});
        return max({one,two,four});
    }

    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        find(root,ans);

        return ans;
    }
};