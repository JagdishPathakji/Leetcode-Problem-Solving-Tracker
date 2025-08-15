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

    TreeNode* find(TreeNode *root, set<int> &s, vector<TreeNode*> &ans) {

        if(!root) 
        return nullptr;

        root->left = find(root->left,s,ans);
        root->right = find(root->right,s,ans);

        if(s.find(root->val) != s.end()) {
            if(root->left)
            ans.push_back(root->left);
            if(root->right)
            ans.push_back(root->right);

            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        set<int> s(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;

        find(root,s,ans);
        if(s.find(root->val) == s.end()) 
        ans.push_back(root);

        return ans;
    }
};