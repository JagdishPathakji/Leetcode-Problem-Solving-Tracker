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

    void findDepth(TreeNode *root, int curr, int &ans) {

        if(!root) {
            ans = max(curr,ans);
            return;
        }

        curr += 1;

        findDepth(root->left,curr,ans);
        findDepth(root->right,curr,ans);

        curr -= 1;
    }

    int maxDepth(TreeNode* root) {
        
        if(!root)
        return 0;

        if(!root->left && !root->right)
        return 1;

        int ans = 0;
        findDepth(root,1,ans);

        return ans-1;
    }
};