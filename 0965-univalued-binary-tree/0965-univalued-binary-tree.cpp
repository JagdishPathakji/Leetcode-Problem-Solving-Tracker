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

    void find(TreeNode *root, bool &check, int &prev) {

        if(!root) return;

        if(!check) return;

        if(root->val != prev and prev != INT_MIN)
        check = false;

        prev = root->val;
        find(root->left,check,prev);
        find(root->right,check,prev);
        
    }

    bool isUnivalTree(TreeNode* root) {
        
        bool check = true;
        int prev = INT_MIN;
        find(root,check,prev);

        return check;
    }
};