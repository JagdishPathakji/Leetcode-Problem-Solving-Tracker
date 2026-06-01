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

    int traverse(TreeNode *root, unordered_map<TreeNode*, pair<int,int>> &mp, int level) {

        if(!root) return 0;

        if(!root->left && !root->right) return root->val;

        int left = traverse(root->left,mp,level+1);
        int right = traverse(root->right,mp,level+1);

        mp[root] = {left+right,level};

        return root->val;
    }

    void solve(TreeNode *root, unordered_map<TreeNode*, pair<int,int>> &mp, unordered_map<int,int> &levelandsum, int level) {

        if(!root) return;
        if(!root->left && !root->right) return;

        int childsum = 0;
        if(root->left)
        childsum += root->left->val;
        if(root->right)
        childsum += root->right->val;

        int sum = levelandsum[level] - childsum;
        if(root->left)
        root->left->val = sum;
        if(root->right)
        root->right->val = sum;

        solve(root->left,mp,levelandsum,level+1);
        solve(root->right,mp,levelandsum,level+1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        
        unordered_map<TreeNode*,pair<int,int>> mp;
        traverse(root,mp,1);

        unordered_map<int,int> levelandsum;
        for(auto it : mp) {
            levelandsum[it.second.second] += it.second.first;
        }

        solve(root,mp,levelandsum,1);

        root->val = 0;
        if(root->left)
        root->left->val = 0;
        if(root->right)
        root->right->val = 0;
        return root;
    }
};