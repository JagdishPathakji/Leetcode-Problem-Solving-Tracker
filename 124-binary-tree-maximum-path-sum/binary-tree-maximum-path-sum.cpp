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

    int maxSum;

    int solve(TreeNode *root) {

        if(root == nullptr) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int bothGaveGoodAns = l + r + root->val;
        int onlyOneGaveGoodAns = max(l,r) + root->val;
        int bothGaveBadAns = root->val;

        maxSum = max({maxSum,bothGaveGoodAns,onlyOneGaveGoodAns,bothGaveBadAns});

        return max(onlyOneGaveGoodAns,bothGaveBadAns); // not for bothGaveGoodAms
    }

    int maxPathSum(TreeNode* root) {
        
        maxSum = INT_MIN;
        solve(root);

        return maxSum;
    }
};