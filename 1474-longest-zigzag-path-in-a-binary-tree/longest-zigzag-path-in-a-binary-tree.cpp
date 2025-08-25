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

    int longestPath = 0;
    void solve(TreeNode *root, bool left, bool right, int currPath) {

        if(!root)
        return;
        
        longestPath = max(longestPath,currPath);
        
        if(left) {
            solve(root->left,false,true,currPath+1);
            solve(root->right,true,false,1);
        }
        
        if(right) {
            solve(root->left,false,true,1);
            solve(root->right,true,false,currPath+1);
        }
        
    }

    int longestZigZag(TreeNode* root) {
        
        solve(root,true,true,0);

        return longestPath;
    }
};