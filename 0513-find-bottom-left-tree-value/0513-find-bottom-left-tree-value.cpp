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

    void find(TreeNode *root, int &ans, int level, int &plevel) {

        if(!root) return;

        if(!root->left and !root->right and plevel < level) {
            ans = root->val;
            plevel = level;
        }

        find(root->left,ans,level+1,plevel);
        find(root->right,ans,level+1,plevel);
    }

    int findBottomLeftValue(TreeNode* root) {
        
        int ans;
        int level = 0;
        int plevel = INT_MIN;

        find(root,ans,level,plevel);

        return ans;
    }
};