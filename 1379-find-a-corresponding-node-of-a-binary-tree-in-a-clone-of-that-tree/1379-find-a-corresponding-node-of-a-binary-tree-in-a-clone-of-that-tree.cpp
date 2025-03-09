/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void find(TreeNode *root, int data, TreeNode *&ans) {

        if(!root)
        return;

        if(ans != nullptr)
        return;

        find(root->left,data,ans);
        if(root->val == data) 
        ans = root;
        find(root->right,data,ans);

    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        int data = target->val;
        TreeNode *root = nullptr;
        find(cloned,data,root);

        return root;
    }
};