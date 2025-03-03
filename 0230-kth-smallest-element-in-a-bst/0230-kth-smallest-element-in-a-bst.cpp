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

    void find(TreeNode *root, int &k, int &ans) {

        if(!root)
        return;
        
        if(k==0)
        return;

        find(root->left,k,ans);
        
        k = k - 1;
        
        if(k == 0) {
            ans = root->val;
        }
        
        find(root->right,k,ans);

    }

    int kthSmallest(TreeNode* root, int k) {

        int ans = 0;
        find(root,k,ans);

        return ans;
    }
};